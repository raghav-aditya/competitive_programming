/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) begin(x) , end(x) 
#define mask(i) (1LL << (i))
#define vi vector<int>
#define vvi vector<vi>
const int mod = pow(10,9)+7 ;
const int MAX = pow(10,5)+1 ;
const int dx[8] = { 1 , -1 , 0 , 0 , 1 , 1 , -1 , -1 } ;
const int dy[8] = { 0 , 0 , 1 , -1 , 1 , -1 , 1 , -1 } ;
int mod_pow( int a , int b )
{
    if( a == 0 || a == 1 ) return a ;
    if( b == 0 )return 1 ;
    int ha = mod_pow( a , b/2 ); ha *= ha; ha %= mod ; if( b&1 ) ha *= a ;
    return ha%mod ;
}
int inverse( int a )
{
    return mod_pow(a,mod-2);
}
vector<int>factorial_ ; 
vector<int> factorial( int N = MAX )
{
    vector<int>f(N,1);
    for( int i = 2 ; i < N ; i++ )f[i] = (i*f[i-1])%mod;
    return f ;
}
void init_factorial(){ if(factorial_.size()==0)factorial_ = factorial(); }
#define oo (int)pow(2L,60)
#define arr array<int,3> 
#define ar array<int,2>

int nCr( int N , int R )
{
    if(factorial_.size()==0) factorial_ = factorial();
    int res = factorial_[N]; res *= inverse( factorial_[R] );  
    res = (res%mod+mod)%mod; res *= inverse( factorial_[N-R] ); 
    res = (res%mod+mod)%mod; return res ;
}

/********** GO DOWN ***********/

/* 
   If the genius trains just as hard.... 
   what chance do I have to beat him? 
*/

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void
    {
    	int N , M ;
    	cin>>N>>M ;

    	vector<ar>A(M);
    	for( auto &x : A ){
    		cin>>x[0]>>x[1];
    		x[0]--;
    		x[1]--;
    	}


    	int Q ;
    	cin>>Q ;

    	vector< int > task(Q);

    	for( auto &x : task ){
    		cin>>x ;
    		x--;
    	}

    	vector<int>P(N+1,0);

    	auto get = [&]( int a,  int b)->int{
    		return P[b+1] - P[a];
    	};



    	auto ok = [&]( int m )-> bool{
    		vector< int > t(N,-1);
    		for( int i = 0 ; i < m ; i++ )
    			t[task[i]]=1;

    		P[0] = 0 ;

    		for( int i = 0 ; i < N ; i++ )
    			P[i+1] = P[i] + t[i] ;

    		for( auto x : A )
    		{
    			int a = x[0];
    			int b = x[1];

    			if( get( a , b) > 0 )
    				return 1 ;
    		}

    		return 0 ;
    	};

    	int l = 0 ;
    	int h = Q ;

    	while( l < h )
    	{
    		int m = (l+h)>>1 ;

    		if(ok(m))
    			h = m-1;
    		else
    			l = m+1;
    	}

    	for( int m = l-1 ; m <= l+1 ; m++ )
    	{
    		if( m >= 0 && m <= Q && ok(m) )
    		{
    			cout<<m<<endl;
    			return ;
    		}
    	}
    	cout<<-1<<endl;
    };
    

    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
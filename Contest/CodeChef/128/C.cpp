/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) begin(x) , end(x) 
#define on(i) (1LL << (i))
#define mask(i) (on(i)-1LL)
#define vi vector<int>
#define vvi vector<vi>
const int mod = pow(10,9)+7 ;
const int MAX = pow(10,5)+1 ;
const int dx[8] = { 1 , -1 , 0 , 0 , 1 , 1 , -1 , -1 } ;
const int dy[8] = { 0 , 0 , 1 , -1 , 1 , -1 , 1 , -1 } ;
int mod_pow( int a , int b , int md = mod )
{
    if( a == 0 || a == 1 ) return a ;
    if( b == 0 )return 1 ;
    int ha = mod_pow( a , b/2 ); ha *= ha; ha %= md ; if( b&1 ) ha *= a ;
    return ha%md ;
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


int go( vector<string>B )
{
	int res = 0 ;

	do{
		string A ;
		for( auto x : B )
		{
			A += x ;
		}
		int N = A.size();

		auto ok = [&]( int a , int b )-> int{
			for( int i = a+1 ; i <= b ; i++ )
			{
				if( A[i] < A[i-1] )
					return 0 ;
			}
			return 1 ;
		};


		res = max( res , 1LL );

		for( int i = 0 ; i < N ; i++ )
		for( int j = i ; j < N ; j++ )
		{
			if( ok(i,j) )
				res = max( res , j-i+1 );
		}
	}while( next_permutation(all(B)));
	return res ;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void{
        	
        int N ;
        cin>>N ;
        string A;
        cin>>A ;
        N /= 2 ;

        map< string , int > mp ;

        mp["00"] = 0 ;
        mp["01"] = 1 ;
        mp["10"] = 2 ;
        mp["11"] = 3 ;

        int a, b , c , d ;
        a = 0 ;
        b = 0 ;
        c = 0 ;
        d = 0 ;
        for( int i = 0 ; i < N ; i++ )
        {
        	string v = A.substr( 2*i , 2 );
        	
        	if( mp[v] == 0 )
        		a++;
        	else if( mp[v] == 1 )
        		b++;
        	else if( mp[v] == 2 )
        		c++;
        	else
        		d++;
        }

        int res = 0 ;
        vector<string>B ;

        if( a > 0 )
        {
        	B.push_back("00");
        	res += 2*(a-1);
        }

        if( d > 0 )
        {
        	B.push_back("11");
        	res += 2*(d-1);
        }

        if( b > 0 )
        {
        	int g = min( 2LL , b );
        	while(g--)
        	{
        		B.push_back("01");
        	}
        }

        if( c > 0 )
        {
        	int g = min( 2LL , c );
        	while( g-- )
        	{
        		B.push_back("10");
        	}
        }
        // cout<<B.size()<<endl;
        sort( B.begin() , B.end() );
        res += go( B );
        cout<<res<<endl;
    };
    

int test = 1 ;
cin>>test;
while(test--)
solve();
return 0;
}   
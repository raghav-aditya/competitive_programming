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
vector<int> factorial( int N = MAX )
{
    vector<int>f(N,1);
    for( int i = 2 ; i < N ; i++ )f[i] = (i*f[i-1])%mod;
    return f ;
}
#define oo (int)pow(2L,60)
#define arr array<int,3> 
#define ar array<int,2>

/********** GO DOWN ***********/

/* 
   If the genius trains just as hard.... 
   what chance do I have to beat him? 
*/

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    auto solve = [&]()->void
    {
        int N ;
        cin>>N ;
        vector<int>A(N-1);

        set<int>st;
        for( int i = 1 ; i <= N ; i++ )
        	st.insert(i);
        for( auto &x : A ){ cin>>x ; 
        	st.erase(x);
    	}

    	int g = *st.begin();

    
    	vector<int>back(N-1,0);

    	int j = N ;

    	for( int i = N-2 ; i >= 0 ; i-- )
    	{
    		back[i] = max( j , A[i] );

    		if(i<N-2)
    			back[i] += back[i+1];

    		j--;
    	}

    	vector<int>front(N-1,0);

    	j = 1 ;
    	for( int i = 0 ; i < N-1 ; i++ )
    	{
    		front[i] = max( j , A[i] );

    		if(i>0)
    		front[i] += front[i-1];

    		j++; 
    	}

    	for( auto x : front )
    		cout<<x<<" ";
    	cout<<endl;
    	for( auto x : back )
    		cout<<x<<" ";
    	cout<<endl;


    	int add = (g != N);

    	// int res = 0 ;
    	int mx = max({
    		max(1LL,g) + back[0] + add ,
    		max(N,g) + front[N-2] + add 
    	});


    	int lc = max(1LL,g) + back[0] + add ;
    	cout<<lc<<" ";
    	lc = max(N,g) + front[N-2] + add ;	

    	cout<<lc<<endl;

    	for( int i = 1 ; i < N-1 ; i++ )
    	{
    		lc = front[i-1] + max(i+1,g) + back[i] + add ;
    		mx = max( mx , lc );

    		cout<<lc<<" ";
    	}

    	cout<<endl;

    	cout<<mx<<endl;
    	cout<<endl;
    	cout<<endl;


    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
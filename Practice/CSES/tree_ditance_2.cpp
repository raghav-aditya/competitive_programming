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


void dfs1( vector<int>g[] , vector<int>&dp , vector<int>&sz , int u , int p )
{
	sz[u] = 1 ;
	for( auto v : g[u] )
	{
		if( v != p )
		{
			dfs1( g , dp , sz , v , u );

			sz[u] += sz[v] ;
			dp[u] += ( sz[v] + dp[v] );
		}
	}
}

void redo( vector<int>&dp , vector<int>&sz , int root , int child )
{
	int root_size = sz[root] - sz[child];
	int root_dp =  dp[root] - ( sz[child] + dp[child] );

	sz[child] += root_size ;
	dp[child] += root_size + root_dp ;
}

void dfs2( vector<int>g[] , vector<int>&dp , vector<int>&sz , int u , int p )
{
	for( auto v : g[u] )
	{
		if( v == p )
			continue ;
		redo( dp , sz , u , v );
		dfs2( g , dp , sz , v , u );
	}
}

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    auto solve = [&]()->void
    {
        int N ;
        cin>>N ;
        vector<int>g[N];
        for( int i = 0 ; i < N-1 ; i++ )
        {
        	int a , b ;
        	cin>>a>>b ;
        	a--;
        	b--;
        	g[a].push_back(b);
        	g[b].push_back(a);
        }

        vector<int>dp(N,0);
        vector<int>sz(N,0);

        dfs1( g , dp , sz , 0 , -1 );
        dfs2( g , dp , sz , 0 , -1 );

        for( auto x : dp )
        	cout<<x<<" ";
        cout<<endl;
    };
    

        
    
    solve();
    
    return 0;
}
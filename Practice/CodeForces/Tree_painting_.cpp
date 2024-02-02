/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/

// https://codeforces.com/contest/1187/problem/E

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


vector<int>sz;
vector<int>dp;

void dfs( int u , int p , vector<int>g[] )
{
	for( auto v : g[u] )
	{
		if(v==p)continue;

		dfs(v,u,g);

		sz[u] += sz[v];
		dp[u] += dp[v];
	}
	dp[u] += sz[u] ;
}

void redo( int root , int v )
{
	int root_new_size = sz[root] - sz[v] ;
	int root_new_dp   = dp[root] - ( dp[v] + sz[v] );

	sz[v] += root_new_size ;
	dp[v] += root_new_size + root_new_dp ;
}

void dfs1( int root , int p , vector<int>g[] )
{
	for( auto v : g[root] )
	{
		if(v==p)continue;

		redo( root , v );
		dfs1( v , root , g );
	}
}



int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    auto solve = [&]()->void
    {
    	int N;
    	cin>>N ;
    	vector<int>g[N];
        
    	sz.assign(N,1);
    	dp.assign(N,0);

        for( int i = 0 ; i < N-1 ; i++ )
        {
        	int a , b ; cin>>a>>b ;
        	a--;b--;
        	g[a].push_back(b);
        	g[b].push_back(a);
        }

        dfs( 0 , -1 , g );
        dfs1( 0 , -1 , g );

      	cout<<*max_element(all(dp))<<endl;
    };
    

        
    int test = 1 ;
    // cin>>test;
    while(test--)
    solve();
    
    return 0;
}
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


vi dp ;
vvi g ;

void dfs( int root , int p )
{
	int prod = 1 ;
	for( auto v : g[root] )
	{
		if( v == p )continue;
		dfs(v,root);
		prod *= dp[v];
		prod %= mod ;
	}
	dp[root] = 1 + prod ;
}
void redo( int root , int v )
{
	int root_new_dp = 1 + ( (dp[root]-1) * inverse(dp[v]) )%mod ;
	dp[v] = 1 + (dp[v]-1)*(root_new_dp);
	dp[v] %= mod ;
}
void dfs1( int root , int p )
{
	for( auto v : g[root] )
	{
		if( v == p )continue ;
		redo(root,v);
		dfs1(v,root);
	}
}

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    auto solve = [&]()->void
    {
        int N , M ;
        cin>>N>>M ;
        // mod = M ;

        g.assign(N,vi());
        dp.assign(N,2);

        for( int i = 0 ; i < N-1 ; i++ )
        {
        	int a , b ; cin>>a>>b ; a--;b--;

        	g[a].push_back(b);
        	g[b].push_back(a);
        }

        dfs(0,-1);
        dfs1(0,-1);

        for( auto x : dp )
        	cout<<(x-1)%M<<endl;
    };
    
 	
        
    int test = 1 ;
    // cin>>test;
    while(test--)
    solve();
    
    return 0;
}
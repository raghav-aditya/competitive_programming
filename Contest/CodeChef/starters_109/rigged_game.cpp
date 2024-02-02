/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
    return mod_pow(a%mod,mod-2);
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

vector<int>sz,dp,A ;
vvi g ;

void dfs( int root , int p )
{
    for( auto v : g[root] )
    {
        if( v != p )
        {
            dfs(v,root);
            sz[root] += sz[v] ;
            dp[root] += sz[v] + dp[v] ;

            sz[root] %= mod ;
            dp[root] %= mod ;
        }
    }
}

void redo_calculation( int root , int v )
{
    int new_root_size = sz[root] - sz[v];
    int new_root_dp   = dp[root] - ( sz[v] + dp[v] );

    sz[v] += new_root_size + mod ;
    dp[v] += new_root_size + new_root_dp + mod;

    sz[v] %= mod ;
    dp[v] %= mod ; 
}

void dfs1( int root , int p )
{
    for( auto v : g[root] )
    {
        if( v != p )
        {
            redo_calculation(root,v);
            dfs1( v , root );
        }
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
      
        sz.assign(N,1);
        dp.assign(N,0);
        A.resize(N);
        g.assign(N,vi());


        for( auto &x : A )cin>>x ;
        for( int i = 0 ; i < N-1 ; i++ )
        {
            int a , b ; cin>>a>>b ;
            a--;b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        dfs( 0 , -1);
        dfs1(0 , -1);
        
        sort(all(A));
        sort(all(dp));
        int sum = accumulate(all(A),0LL)%mod;
        int sq = (N*N)%mod ;
        
        sum = (sum*sq)%mod;

        int other_part = 0 ;
        
        for( int i = 0 ; i < N ; i++ )
            other_part = ( other_part + ( A[i]*dp[i] )%mod )%mod ;

        int total = ((sum - other_part) + mod)%mod ;
        
        total = (total * inverse( sq )) % mod ;;
        
        cout<<total<<endl;
    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
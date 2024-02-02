#include <bits/stdc++.h>
using namespace std ;

class Solution {
    vector<int>sz , dp , res ;
    vector< vector<int> > g ;

    void dfs( int u , int p )
    {
        for( auto v : g[u] )
        if(v!=p)
        {
            dfs( v , u );
            sz[u] += sz[v] ;
            dp[u] += dp[v] + sz[v] ; 
        }
    }

    // should recalculate these two things for child(v) when he becoms new root
    
    /*
        1. size 
        2. dp          
    */

    void redo_calculation( int root , int v )
    {
        int new_root_size = sz[root] - sz[v] ;
        int new_root_dp   = dp[root] - (dp[v] + sz[v]) ;

        // root became child of node v, 
        // so v should have to add the contribution 
        // of root as a child  

        sz[v] += new_root_size ; 
        dp[v] += new_root_size + new_root_dp ;
    }

    void dfs2( int root , int p )
    {
        for( auto v : g[root] )
        if( v != p )
        {
            redo_calculation( root , v );
            dfs2( v , root );
        }
    }

public:
    vector<int> sumOfDistancesInTree(int N , vector<vector<int>>& E ) {
        
        sz.resize(N,1);
        dp.resize(N,0);
        res.resize(N,0);
        g.resize(N);

        for( auto x : E )
        {
            int a = x[0] ;
            int b = x[1] ;

            g[a].push_back(b);
            g[b].push_back(a);
        }

        dfs(0,-1);
        dfs2(0,-1);
        return dp ;
    }
};



/*

PROBLEM SET: 
        https://codeforces.com/blog/entry/68142
        https://usaco.guide/gold/all-roots?lang=cpp


Videos:
        https://www.youtube.com/watch?v=7_huTWwl5jM

Blogs: 
        https://discuss.codechef.com/t/dynamic-programming-on-tree-complete-series/70921  [ CSES PROBLEM SET ]
        https://codeforces.com/blog/entry/102087 
        https://codeforces.com/blog/entry/96651
        https://codeforces.com/blog/entry/20935
        https://codeforces.com/blog/entry/61572

ONLINE ALG:
        https://codeforces.com/blog/entry/76150 -> https://codeforces.com/blog/entry/98364
        https://codeforces.com/blog/entry/78564



DIAMETER:
        https://codeforces.com/blog/entry/101271
DFS TREE:
        https://codeforces.com/blog/entry/68138

Tree ISOMORPH:
        https://codeforces.com/blog/entry/101010

Bridge Tree:
        https://codeforces.com/blog/entry/99259


LI CHAO TREE:( CHT )

            https://codeforces.com/blog/entry/86731
            https://codeforces.com/blog/entry/63823 ( CHT )


*/


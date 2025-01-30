#include <bits/stdc++.h>
using namespace std ;

class seg_tree{

    vector<int>T ;
    int N ;

public:

    int join( int a , int b ){
        // to do 
        return max( a , b );
    }

    seg_tree(){}
    seg_tree( vector<int>&A )
    {
        this->N = A.size();
        T.resize(2*N,0);

        for( int i = 0 ; i < N ; i++ )
            T[i+N] = A[i];

        for( int i = N-1 ; i > 0 ; i-- )
            T[i] = join( T[i<<1] , T[i<<1|1] ) ;
    }

    int get( int a , int b ){
        int res = 0 ;
        for( a += N , b += N+1 ;  a < b ; a >>= 1 , b >>= 1 ){
            if(a&1) res = join( res , T[a++] ) ;
            if(b&1) res = join( res , T[--b] ) ;
        }
        return res;
    }

    void update( int p , int x ){
        p += N ;
        T[p] = x ;
        for( ; p >>= 1 ; )
            T[p] =  join( T[2*p] , T[2*p+1] ) ;
    }


};
 
 
class HLD{
 
    vector<int>H,head,par;
    vector<int>tin,tout;
    int timer = 0 ;
    vector<int>D ; // depth 
    vector< vector<int> > g ; // graph 
    int N ;
    vector<int>E ; // euler tour 
    seg_tree st ;
 
    int join( int a , int b ){
        return st.join( a , b );
    }

    int dfs( int u , int p )
    {
        int sz = 1 ;
        int mx = 0 ; 
 
        for( auto v : g[u] )
        {
            if( v == p )continue ;
            
            par[v] = u ;
            D[v] = D[u] + 1 ;
            int c_sz = dfs( v , u );
 
            sz += c_sz ;
            if( c_sz > mx )
            {
                mx = c_sz ;
                H[u] = v ;
            }
        }
        return sz ;
    }
 
 
    void hld( int h , int u , int p )
    {
 
        tin[u] = ++timer;
        E.push_back(u);
 
        head[u] = h;
        if( H[u] != -1 )
            hld( h , H[u] , u );
 
        for( auto v : g[u] )
        {
            if( v == p || v == H[u] )continue ;
            hld( v , v, u );
        }
 
        tout[u] = timer ;
    }
 
    bool is_ancestor( int a,  int b ){
        return tin[a] <= tin[b]  &&  tout[b] <= tout[a] ;
    }
 
 
public:
 
    HLD( const vector<vector<int>>&g_ ){
 
        // 0 based index 
 
        this->g = g_;
        this->N = g.size();
 
        H.resize(N,-1);
        head.resize(N,0);
        par.resize(N,0); // root's parent is root
        tin.resize(N,0);
        tout.resize(N,0);
        D.resize(N,0);
        dfs(0,-1);
 
        timer = -1 ;
        hld(0,0,-1);
    }
 
    void fill( const vector<int>&A )
    {
        for( auto &x : E )
            x = A[x] ;
            
        seg_tree st_(E);
        st = st_ ;
    }
 
    int query( int a , int b )
    {
        int res = 0 ;
        for( ; head[a] != head[b] ; b = par[head[b]] ){
 
            if( D[head[a]] > D[head[b]] )
                swap( a , b );
 
            int end = tin[b];
            int start = tin[head[b]];
 
            res = join( res , st.get( start , end ));
        }
 
        if( D[a] > D[b] )
            swap( a, b );
 
        int start = tin[a];
        int end = tin[b];
 
        res = join( res , st.get( start , end ));
 
        return res;
    }
    
    void update( int node , int x )
    {
        int k = tin[node];
        E[k] = x ;
        st.update(k , x);
    }
};
 

/*

Explanation of fill method:

https://cses.fi/problemset/result/8931980/

*/
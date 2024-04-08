#include <bits/stdc++.h>
using namespace std ;

#define ar array<int,2>
#define arr array<int,3>

class seg_tree{

    vector<int>T ;
    int N ;

public:

    int join( int a , int b ){
        // to do 
        return a + b ;
    }

    seg_tree(){}
    seg_tree( const vector<arr>&A )
    {
        this->N = A.size();
        T.resize(2*N,0);

        for( int i = 0 ; i < N ; i++ )
            T[i+N] = A[i][2];

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


class HLD
{

    vector<int>in,out;
    vector<int>head,H,D,W;
    vector<arr>E ; // from , to , w 
    vector<int>par ;
    int N ;
    vector< vector<ar> > g ;
    int timer = -1 ;
    seg_tree st ;


    int join( int a, int b ){
       return st.join( a , b );
    }

    int dfs( int u , int p )
    {
        int mx = 0 ;
        int sz = 1 ;
        for( auto x : g[u] )
        {
            int v = x[0];
            if( v == p )continue ;
            D[v] = D[u] + 1 ;
            int c = dfs( v , u );
            sz += c ;

            if( c > mx )
            {
                mx = c ;
                H[u] = v ;
                W[u] = x[1];
            }
        }
        return sz ;
    }

    void hld( int u , int p , int h , int w )
    {
        head[u] = h ;
        E.push_back({ p , u , w });
        in[u] = ++timer ;
        par[u] = p ;

        if( H[u] != -1 )
            hld( H[u] , u , h , W[u] );

        for( auto x : g[u] )
        {
            int v = x[0];
            int vw = x[1];

            if( v == p || v == H[u] )continue;
            hld( v , u , v , vw );
        }
        out[u] = timer ;
    }

    int lca( int a , int b )
    {
        for( ; head[a] != head[b] ; b = par[head[b]] )
        {
            if( D[head[a]] > D[head[b]] )
                swap( a , b );
        }

        if( D[a] > D[b] )
            swap( a , b );
        return a ;  
    }

    int query( int l , int a )
    {
       int res = 0 ;
        
        if( l == a )
        {
            return res ; 
        }       

        for( ; head[a] != head[l] ; a = par[ head[a] ] )
        {
            int start = in[head[a]];
            int end = in[a];
            res = join( res , st.get( start , end ) );
        }
        
        int start = in[l] + 1 ;
        int end = in[a];

        res = join( res , st.get( start , end ) ) ;       

        return res; 
    }

public:

    HLD( vector<vector<ar>> &g_ )
    {
        this->g = g_ ;
        this->N = g.size();
        in.resize(N,0);
        out.resize(N,0);
        head.resize(N,0);
        H.resize(N,-1);
        D.resize(N,0);
        W.resize(N,0);
        par.resize(N,0);
        timer = -1 ;

        dfs( 0 , 0 );
        hld( 0 , 0 , 0 , 0 );
        seg_tree st_(E);
        this->st = st_ ;
    }

    void update( int a , int b , int w )
    {
        if( D[a] > D[b] )
            swap( a , b );

        // be should be away from root 
        int k = in[b];
        st.update( k , w );
    }

    int path_max( int a , int b )
    {
        if( a == b )
            return 0 ;
        int l = lca( a , b );
        return join( query( l , a ) , query( l , b ) );
    }
};
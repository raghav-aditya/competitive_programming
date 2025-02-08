
#include <bits/stdc++.h>
using namespace  std ;

class DSU
{
    vector< int > par ;
    vector< int > size ;
    int N ;
    int cnt ;
    int mx ;

public:

    DSU( int sz )
    {
        this->N = sz ;
        cnt = N ;
        mx = 1 ;
        par.resize(N,0);
        iota( par.begin() , par.end() ,0);
        size.resize(N,1);
    }

    int find( int x )
    {
        if( par[x] == x )
            return x ;
        return par[x] = find( par[x] );
    }

    int get( int x )
    {
        return size[find(x)] ;
    }

    void join( int a , int b )
    {
        if( is_same( a, b) )
            return ;
        
        int L = get(a) ;
        int R = get(b) ;

        if( L > R )
        {
            swap( L , R );
            swap( a , b );
        }

        par[find(a)] = find(b);
        size[find(a)] = L + R ;

        cnt--;
        mx = max( mx , L+R );
    }

    bool is_same( int a , int b )
    {
        if( find(find(a)) == find(find(b)) )
        return 1 ;

        return 0 ;
    }

    bool check()
    {
        set<int>st;
        for( int i = 0 ; i < N ; i++ )
            st.insert(find(i));

        return st.size()==1;
    }

    int get_count()
    {
        return cnt ;
    }

    int get_max()
    {
        return mx ;
    }
};
/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ar array<int,2>


class seg_tree{

    vector<ar>T ;
    int N ;

public:
    seg_tree( vector<int>&A )
    {

        this->N = A.size();
        T.resize(2*N);

        for( int i = 0 ; i < N ; i++ )
            T[i+N][0] = T[i+N][1] = A[i];

        for( int i = N-1 ; i > 0 ; i-- )
        {
            T[i][0] = min( T[2*i][0] , T[2*i+1][0] );
            T[i][1] = max( T[2*i][1] , T[2*i+1][1] );
        }
    }

    int get_max( int a , int b)
    {
        int res = 0 ;
        for( a += N , b += N+1 ; a < b ; a >>= 1 , b >>=1 ){
            if(a&1) res = max( res , T[a++][1] );
            if(b&1) res = max( res , T[--b][1] );
        }
        return res;
    }


    int get_min( int a , int b )
    {
        int res = N+1 ;
        for( a += N , b += N+1 ; a < b ; a >>= 1 , b >>= 1 ){
            if(a&1) res = min( res , T[a++][0] );
            if(b&1) res = min( res , T[--b][0] );
        }
        return res;
    }
};

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void
    {
    	
    	int N ;
    	cin>>N ;
    	vector< int > A(N);
    	for( auto &x : A )cin>>x ;
        seg_tree st( A ) ;
        unordered_map< int , int > ind ;

        for( int i = 0 ; i < N ; i++ )
            ind[A[i]] = i ;

        int l = ind[N];
        int r = ind[N];

        int res = 1 ;

        // [ l , r ] -> range we have cut out from array 
        for(  int v = N-1 ; v > 1 ; v-- )
        {
            int k = ind[v] ;

            l = min( k , l ); // we will expand out cutout range 
            r = max( k , r );

            // out range is whatever out side the cut out range that is 
            // out range = [ 0 , l-1 ] + [ r+1 , N-1 ]

            int out_min = min( st.get_min( 0 , l-1 ) , st.get_min( r+1 , N-1 ) );
            int out_max = max( st.get_max( 0 , l-1 ) , st.get_max( r+1 , N-1 ) );
            int in_min = st.get_min( l , r );

            if( in_min > out_max && out_min == 1 )
                res = r-l+1;
        }
        cout<<res<<endl;    	
    };
    
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
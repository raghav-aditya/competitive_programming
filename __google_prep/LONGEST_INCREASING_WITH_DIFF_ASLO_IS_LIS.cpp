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

class seg_tree{
    vector< int > T ;
    int N ;
public:
    seg_tree(){
    }

    seg_tree( const vector<ar>&A )
    {
        this->N = A.size();
        T.resize(2*N,0);

        for( int i = 0 ; i < N ; i++ )
            T[i+N] = A[i][1];
        for( int i = N-1 ; i > 0 ; i-- )
            T[i] = max( T[2*i] , T[2*i+1] );
    }

    int get( int a , int b )
    {
        int res = 0 ;
        for( a += N , b += N+1 ; a < b ; a >>= 1 , b >>= 1 )
        {
            if(a&1) res = max( res , T[a++] );
            if(b&1) res = max( res , T[--b] );
        }
        return res ;
    }
};


// ar -> array<int,2> -> { diff , lenght };

int solve( vector<int>&A )
{
    int N = A.size();
    vector< seg_tree > st ;
    vector< vector< ar > > t( N ) ;

    int res = 0 ;

    for( int i = 0 ; i < N ; i++ )
    {
        t[i].push_back({0,1});

        res = max( res , 1LL );

        for( int j = 0 ; j < i ; j++ )
        {
            int diff = A[i]-A[j];
            if( diff <= 0 )
                continue;

            int k = upper_bound( t[j].begin() , t[j].end() , ar{ diff , INT_MIN } ) - t[j].begin() ;

            int len = st[j].get( 0 , k-1 );

            if( len > 0 )
            {
                len++;
                res = max( res , len );
                t[i].push_back({ diff , len });
            }
        }

        sort( t[i].begin() ,t[i].end() ); // diff , len 
        seg_tree my_seg_tree(t[i]);
        st.push_back(my_seg_tree);
        
    }
    return res;
}

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> A = { 1 , 11 , 12 , 14 };
    
    cout<<solve( A )<<endl;
    
    return 0;
}
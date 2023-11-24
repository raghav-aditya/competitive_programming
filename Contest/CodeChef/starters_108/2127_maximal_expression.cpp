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

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    


    auto solve = [&]()->void
    {
        int N , k ;
        cin>>N>>k ;

        // f =  x % k * ( (N-x) % k )

        auto f = [&]( int x ) -> int 
        {

            if( x < 0LL || x-N > 0 )
                return -oo ;

            int p = x%k ;
            int q = (N-x+k) % k ;
            return p*q ;
        };

        int hk = k/2 ;
        int hN = N/2 ;
        int m = hk+hN ;
        
        // this is inverted parabola try mid point of intersection with x-axis and some other possibility just draw 
        /*
        
                                . .......... ..........
                            ......                      .....
                           ....                             ...
                        ....                                   ..
                      ...                                       ...
                     ..          xxxxxxxxx        xxxxxxxxxx      ..
                     .          xxx    xxxx      xxxx     xxx      ..
                    ..          xx       xx       x        x x      ..
                    .            xxxxxxxxxx       xxx      x x       .
                    .              xxxxxxxx        xxxxxxxxxxx       .
                    .                        x        xxxxxx         .
                    .                        x                       .
                    ..        xx             x                       .
                     .         xx            x              xxx     ..
                     ..        xxxxx                      xxxx     ..
                      ..        xxxxxxxxxxx        xxxxxxxxx      ..
                       ..            xxxxxxxxxxxxxxxxxxxx        ..
                        ...                                     ..
                          .....                              ....
                              ......                     ....
                                    .....................
        
        */
        
        vector< int > can 
        {
            m , m-1 , m+1 ,
            hk , hk-1, hk+1 ,
            0 , 1 , N-1 , N ,
            hN , hN-1 , hN+1 
        };

        int res = 0 ; 
        int ans = 0 ;

        for( auto x : can )
        {
            int local = f(x);

            if( res < local )
            {
                res = local ;
                ans = x ;
            }
        }

        cout<<ans<<endl; 

    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
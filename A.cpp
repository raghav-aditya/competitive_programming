/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) begin(x) , end(x) 
#define on(i) (1LL << (i) )
#define mask(i) (on(i)-1)
#define vi vector<int>
#define vvi vector<vi>
#define arr array<int,3> 
#define ar array<int,2>

const int mod = pow(10,9)+7 ;
const int MAX = pow(10,5)+1 ;
const int dx[8] = { 1 , -1 , 0 , 0 , 1 , 1 , -1 , -1 } ;
const int dy[8] = { 0 , 0 , 1 , -1 , 1 , -1 , 1 , -1 } ;
int mod_pow( int a , int b ){if( a == 0 || a == 1 ) return a ; if( b == 0 )return 1 ; int ha = mod_pow( a , b/2 ); ha *= ha; ha %= mod ; if( b&1 ) ha *= a ; return ha%mod;}
int inverse( int a )
{
    return mod_pow(a,mod-2);
}


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
        int N ;
        cin>>N ;
        vector< int >A(N);
        for( auto &x : A )cin>>x ;

        auto B = A ;
        for( auto x : B )
            A.push_back(x);

        int M = A.size();
        int t[M][M];
        memset( t , 0 , sizeof t );

        vector< int > P(M+1, 0);

        for( int i = 0 ; i < M ; i++ )
            P[i+1] = P[i] + A[i];

        auto get = [&]( int a , int b )->int{
                return P[b+1]-P[a];
        };  

        for( int L = 2 ; L <= N ; L++ )
        for( int i = 0 ; i+L-1<M; i++ )
        {
            int j = i+L-1;
            int cost = get( i , j );
            t[i][j] = pow(10LL,16) ;

            for( int k = i ; k < j ; k++ )
            {
                t[i][j] = min( t[i][j] , t[i][k] + t[k+1][j] + cost );
            }
        }

        int res = pow(10LL,16) ;
        for( int i = 0 ; i+N-1< M ; i++ )
        {
            res = min( res , t[i][i+N-1] );
        }

        cout<<res<<endl;

    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
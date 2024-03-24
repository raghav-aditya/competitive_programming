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
        int N , k , x ;
        cin>>N>>k>>x ;
        vector<int>A(N);
        int res = INT_MIN ;
        for( auto &i : A )cin>>i ;
        sort( A.begin() , A.end() );

        vector<int>P(N+1,0);
        for( int i = 0 ; i < N ; i++ )
            P[i+1] = A[i] + P[i] ;

        auto get = [&]( int a, int b )-> int {
            return P[b+1] - P[a] ;
        };

        auto go = [&]()->int{
            if( A.size() <= x )
            {
                return -get( 0 , A.size()-1 );
            }            

            return get( 0 , A.size()-x-1 ) - get( A.size()-x , A.size()-1 );

        };

        res = max( res , go() );

        while( A.size() && k-- )
        {
            A.pop_back();
            res = max( res , go() );
        }
        cout<<res<<endl;
    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}






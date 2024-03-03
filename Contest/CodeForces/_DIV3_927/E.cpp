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


int go( vector< vector<int> > &A )
{
    int N = A.size();
    vector<int>t(N,0);
    t[N-1] = A[N-1][2];

    for( auto &x : A )
        swap( x[0] , x[1] );

    for( int i = N-2 ; i >= 0 ; i-- )
    {
        
        int b = A[i][1] ;
        int c = A[i][2] ;

        t[i] = c ;

        auto j = lower_bound( all(A) , arr{ b+1 , -1 , -1 } ) - A.begin() ;

        t[i] = max( t[i] , t[i+1] );

        if( j < N )
        {
            t[i] = max({
                t[i],
                c + t[j] 
            });
        }
    }

    return t[0]; 
}



int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    auto solve = [&]()->void
    {
        int N , M ;
        cin>>N>>M ;
        vector< ar > A(M);

        for( auto &x : A )
            cin>>x[0]>>x[1];

        map< ar , int > mp;

        for( auto x : A )
        {
            mp[x]++;
        }

        vector<vector<int>> B;

        for( auto x : mp )
        {
            ar a = x.first ;
            int b = x.second ;
            B.push_back({ a[1] , a[0] , b });
        }

        sort( B.begin() , B.end() );

        cout<<go(B)<<endl;

    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
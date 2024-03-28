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


vector< int > factorial(200010,1) ;

int nCr( int N , int R )
{
    int res = factorial[N];
    res *= inverse( factorial[R] ); 
    res = (res%mod+mod)%mod;
    res *= inverse( factorial[N-R] );
    res = (res%mod+mod)%mod;
    return res ;
}


void dfs( vector<int>g[] , int u , vector<int>&dp , vector<int>&sz )
{
    sz[u] = 1;
    for( auto v : g[u] )
    {
        dfs( g , v , dp , sz );
        sz[u] += sz[v];
    }

    
    int res = 1 ;
    int S = sz[u] - 1;

    for( auto v : g[u] )
    {
        res *= dp[v] * nCr( S , sz[v] ) ;
        res = (res%mod+mod)%mod;
        S -= sz[v];
    }
    
    dp[u] = res ;
}

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for( int i = 2 ; i <= 200009 ; i++ )
        factorial[i] = (factorial[i-1]*i)%mod ;

    auto solve = [&]()->void
    {
        int N , a , b ;
        cin>>N>>a>>b ;

        vector<int>A(a);
        vector<int>B(b);

        for( auto &x : A )cin>>x ;
        for( auto &x : B )cin>>x ;

        if( A.front()  != 1 || B.back() != N || A.back() != B.front() )
        {
            cout<<0<<endl;
            return ;
        }

        for( auto &x : A )x--;
        for( auto &x : B )x--;

        vector< int > g[N] ;

        for(int i = 0; i + 1 < a; i++) {
            g[A[i + 1]].push_back(A[i]);
            for(int j = A[i] + 1; j < A[i + 1]; j++) g[A[i]].push_back(j);
        }

        for(int i = 0; i + 1 <  b; i++) {
            g[B[i]].push_back(B[i + 1]);
            for(int j = B[i] + 1; j < B[i + 1]; j++) g[B[i + 1]].push_back(j);
        }


        vector< int > dp( N , 0 );
        vector< int > sz( N , 0 );

        dfs( g , A.back() , dp , sz );

        cout<<dp[A.back()]<<endl;
    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
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

int solve( int a , int b  , int N , vector<int>&A )
{
        int T = accumulate( A.begin() , A.end() , 0 );
        
        auto get = [&]( int m )-> int {
            int s1 = m ;
            int s2 = T-m ;
            
            int k1 = (s1+a-1)/a ;
            int k2 = (s2+b-1)/b ;
            
            return max( k1 , k2 );
        };
        
        
        vector< vector<int> > t( N+1 , vector<int>(T+1,0));
        
        for( int i = 0 ; i <= N ; i++ )
        t[i][0] = 1;
        
        for( int i = 1 ; i <= N ; i++ )
        for( int j = 1 ; j <= T ; j++ )
        {
            t[i][j] |= t[i-1][j];
            if( j >= A[i-1] )
            t[i][j] |= t[i-1][j-A[i-1]];
        }
        
        int res = INT_MAX ;
        for( int j = 0 ; j <= T ; j++ )
        {
            if(t[N][j])
            res = min( res , get(j) );
        }
        return res;
}

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    int N ;
    cin>>N ;
    int a , b ;
    cin>>a>>b ;
    vector< int >A(N);
    for( auto &x :A )
        cin>>x ;

    cout<<solve( a , b , N , A )<<endl;
    
    return 0;
}
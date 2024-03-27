/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) begin(x) , end(x) 
#define on(i) (1LL << (i))
#define mask(i) (on(i)-1LL)
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
vector<int>factorial_ ; 
vector<int> factorial( int N = MAX )
{
    vector<int>f(N,1);
    for( int i = 2 ; i < N ; i++ )f[i] = (i*f[i-1])%mod;
    return f ;
}
void init_factorial(){ if(factorial_.size()==0)factorial_ = factorial(); }
#define oo (int)pow(2L,60)
#define arr array<int,3> 
#define ar array<int,2>

int nCr( int N , int R )
{
    if(factorial_.size()==0) factorial_ = factorial();
    int res = factorial_[N]; res *= inverse( factorial_[R] );  
    res = (res%mod+mod)%mod; res *= inverse( factorial_[N-R] ); 
    res = (res%mod+mod)%mod; return res ;
}

/********** GO DOWN ***********/

/* 
   If the genius trains just as hard.... 
   what chance do I have to beat him? 
*/


void dfs( vector<int>g[] , int u , int p , vector<ar>&dp , vector<ar>&A )
{
    dp[u][0] = 0 ;
    dp[u][1] = 0 ;

    int a = A[u][0];
    int b = A[u][1];

    for( auto v : g[u] )
    {
        if( v == p )continue ;

        int c = A[v][0];
        int d = A[v][1];

        dfs( g , v , u , dp , A );

        dp[u][0] += max( dp[v][0] + abs( a - c )  ,  dp[v][1] + abs( a-d ) );
        dp[u][1] += max( dp[v][0] + abs( b - c )  ,  dp[v][1] + abs( b-d ) );
    }    
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void
    {
    	int N ;
    	cin>>N ;

    	vector<int>g[N];

    	vector<ar> A(N);
        for( auto &x : A )cin>>x[0]>>x[1];

        for( int i = 0 ; i < N-1 ; i++ )
        {
            int a , b ;
            cin>>a>>b ; a--; b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        vector< ar > dp( N );
        dfs( g , 0 , -1 , dp , A );
        cout<<max( dp[0][0] , dp[0][1] )<<endl;    	
    };
    

    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
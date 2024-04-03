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
int mod_pow( int a , int b , int md = mod )
{
    if( a == 0 || a == 1 ) return a ;
    if( b == 0 )return 1 ;
    int ha = mod_pow( a , b/2 ); ha *= ha; ha %= md ; if( b&1 ) ha *= a ;
    return ha%md ;
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


vector< vector<int> > dp ;
vector<int>A ;
vector<int>res;

void dfs( vector<int>g[] , int u , int p )
{
    dp[u].push_back(A[u]);
    int mx = 1 ;
    int id = -1 ;

    for( auto v : g[u] )
    {
        if( v == p )continue;

        dfs( g , v , u );
        if( dp[v].size() > mx )
        {
            mx = dp[v].size();
            id = v ;
        }
    }

    if( id != -1 )
        swap( dp[id] , dp[u] );

    for( auto v : g[u] )
    {
        if( v == p )continue;

        for( auto x : dp[v] )
            dp[u].push_back(x);
    }
    sort( dp[u].begin() , dp[u].end() );

    res[u] = dp[u].end() - upper_bound( all(dp[u]) , A[u] );
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void{
        int N;
        cin>>N ;
        vector<int>g[N];
        A.resize(N);
        res.resize(N);
        for( auto &x : A )cin>>x ;

        for( int i = 1 ; i < N ; i++ )
        {
            int p ; cin>>p ;
            p--;
            g[p].push_back(i);            
        }

        dp.resize(N);

        dfs( g , 0 , -1 );

        for( auto x : res )
            cout<<x<<endl;
    };
    

int test = 1 ;
// cin>>test;
while(test--)
solve();
return 0;
}   
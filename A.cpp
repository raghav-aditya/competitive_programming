/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

#define int long long
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
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

int N , k ;    
int res = 0 ;
vector< unordered_map< int , int > > dp ;

void dfs( vector<int>g[] , int u , int p , int d )
{
    dp[u][d]++;
    int mx = 0 ;
    int id = -1 ;

    for( auto v : g[u] )
    {
        if( v == p )continue ;

        dfs( g , v , u , d+1 );
        if( dp[v].size() > mx )
        {
            mx = dp[v].size();
            id = v ;
        }
    }

    if( id != -1 )
        swap( dp[u] , dp[id] );

    // a + b = k 
    // (d+a) + (d+b) = 2*d + k 
    // d2 = 2*d + k - (d1);

    for( auto v : g[u] )
    {
        if( v == p )continue ;

        for( auto x : dp[v] )
        {
            int a = x.first ;
            int b = x.second ;

            int look = 2*d + k - a ;
            res += dp[u][look]*b ;
        }

        for( auto x : dp[v] )
        {
            int a = x.first;
            int b = x.second ;
            dp[u][a] += b ;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void{

        cin>>N>>k ;

        vector< int > g[N];
        dp.resize(N);
        for( int i = 0 ; i < N-1 ; i++ )
        {
            int a , b ;
            cin>>a>>b ;
            a--;b--;

            g[a].push_back(b);
            g[b].push_back(a);
        }
        res = 0 ;
        dfs( g , 0,-1,0);
        cout<<res<<endl;
    };
    

int test = 1 ;
// cin>>test;
while(test--)
solve();
return 0;
}   
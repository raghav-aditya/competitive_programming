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

vector< int > dp ;

void dfs( vector<int>g[] , int u , int p , int mask , unordered_map<int,int>&mp , string &A )
{
	int n_mask = mask ;
	int k = (A[u]-'a');
	n_mask ^= (1<<k) ;

	for( int c = 0 ; c  < 26 ; c++ )
	{
		int l_mask = n_mask ^ ( 1<<c ) ;
		dp[u] += mp[l_mask];
	}

	dp[u] += mp[n_mask]++;

	for( auto v : g[u] )
	{
		if( v == p )continue;
		dfs( g , v , u , n_mask , mp , A );
	}

	mp[n_mask]--;
}


vector< int > f( vector< int > &from , vector<int>&to , vector< int > &Q , string &A )
{
	int N = A.size();
	vector<int>g[N];

	for( int i = 0 ; i < N-1 ; i++ )
	{
		int a = from[i];
		int b = to[i];

		g[a].push_back(b);
		g[b].push_back(a);
	}

	dp.assign(N,0);
	unordered_map< int , int > mp ;
	mp[0]++;

	dfs( g , 0 , -1 , 0 , mp , A );	

	vector<int>res;
	for( auto x : Q )
		res.push_back(dp[x]);

	return res ;
}	

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

  		
  	vector< int > from = { 0 , 0 , 1 };
  	vector< int > to = { 1 , 2 , 3 };
  	vector< int > Q = { 3 } ;
  	string A = "zaaa";

  	auto res = f( from , to , Q , A );

  	for( auto x : res )
  		cout<<x<<" ";


return 0;
}   
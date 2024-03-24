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

vector< int > sz ;
int cnt = 0 ;

void dfs( vector<int>g[] , int m , int u , int p ) {

	sz[u] = 1;

	for( auto v : g[u] )
	{
		if( v != p )
		{

			dfs( g , m , v , u );
			sz[u] += sz[v] ;

			if( sz[v] >= m ){
				sz[u] -= sz[v] ;
				cnt++;
			}
		}
	}
}

bool ok( vector<int>g[] , int m , int k , int N )
{
	cnt = 0 ;
	sz.assign( N , 0 );
	dfs( g , m , 0 , -1 ) ;
	if( sz[0] < m )
		cnt-- ;
	return cnt >= k ;
}

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    auto solve = [&]()->void
    {
        
    	int N , k ;
    	cin>>N>>k ;

    	vector< int > g[N];

    	for( int i = 0 ; i < N-1 ; i++ )
    	{
    		int a , b ;
    		cin>>a>>b ;
    		a--;
    		b--;

    		g[a].push_back(b);
    		g[b].push_back(a);
    	}


    	int l = 1 ; 
    	int h = N ;

    	while( l < h )
    	{
    		int m = (l+h)>>1 ;

    		if(ok( g , m , k , N))
    			l = m+1;
    		else
    			h = m-1;
    	}

    	for( int m = l+1 ; m >= l-1 ; m-- )
    	{
    		if( m >=1 && m <= N && ok( g , m , k , N) ){
    			cout<<m<<endl;
    			return ;
    		}
    	}

    	cout<<"Incorrect bounds"<<endl;
    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
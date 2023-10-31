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

#define arr array<int,3> 
#define ar array<int,2>

/********** GO DOWN ***********/

/* 
   If the genius trains just as hard.... 
   what chance do I have to beat him? 
*/

int dis[1000010];


void dfs( int p , int u , vector< ar > g[] , int val )
{

	dis[u] = val ;
	for( auto v : g[u] )
	if( v[0] != p )
	{
		dfs( u , v[0] , g , val ^ v[1] );
	}
}

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	auto solve = [&]()->void
	{
		int N ;
		cin>>N ;
		for( int i = 0 ; i < N ; i++ )dis[i] = 0 ;

		vector< ar > g[N] ;
		for( int i = 0 ; i < N-1 ; i++ )
		{
			int a , b , w ;
			cin>>a>>b>>w ;
			a--; b-- ;
			g[a].push_back({b,w});
			g[b].push_back({a,w});
		}

		dfs(-1,0,g, 0);

		unordered_map< int , ar > mp ;

		for( int i = 0 ; i < N ; i++ )
		for( int j = i+1 ; j <N; j++ )
		{
			int myxor = dis[i] ^ dis[j] ;
			if(mp.find(myxor)!=mp.end())
			{
				cout<<i+1<<" "<<j+1<<" "<<mp[myxor][0]<<" "<<mp[myxor][1]<<endl;
				return ;
			}

			mp[myxor] = { 1+i , 1+j };
		}

		cout<<-1<<endl;
	};
	

		
    int test = 1 ;
	cin>>test;
	while(test--)
	solve();
	
	return 0;
}
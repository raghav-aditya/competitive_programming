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


void dfs( vector<int>g[] , vector<int>&dis , vector<int>&par , int u , int p , int lv )
{
	dis[u] = lv ;
	par[u] = p ;

	for( auto v : g[u] )
	{
		if( v != p ){
			dfs( g , dis , par , v , u , lv+1 );
		}
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
        
        vector<int>g[N];


        for( int i = 0 ; i < N-1 ; i++ )
        {
        	int a , b ;
        	cin>>a>>b ;

        	a--;b--;

        	g[a].push_back(b);
        	g[b].push_back(a);
        }

        vector< int > dis( N , 0 );
        vector< int > par( N ,-1 );

        dfs( g , dis , par , 0 , -1 , 0 );
		
		int x = max_element( dis.begin() , dis.end() ) - dis.begin();
		
		dfs( g , dis , par , x , -1 , 0 );
		
		int y = max_element( dis.begin() , dis.end() ) - dis.begin();


		vector<int>path ;

		while( y != -1 )
		{
			path.push_back(y);
			y = par[y] ;
		}

		int left = N - path.size() ;

		string res(N,'.');
		
		for( int i = 0 ; i < path.size() ; i++ )
		{
			if( i < path.size()/2 )
			{
				res[ path[i] ] = 'R';
			}
			else
			{
				res[ path[i] ] = 'B' ;
			}
		}

		int ha = (left+1)/2;

		for( auto &i : res )
		{
			if( i == '.' )
			{
				if( ha-- > 0 )
				{
					i = 'R';
				}
				else
					i = 'B';
			}
		}

		cout<<res<<endl;

    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
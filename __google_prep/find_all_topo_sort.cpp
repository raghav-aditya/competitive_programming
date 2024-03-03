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

void rec( vector<int>&inD , vector<int>g[] , vector<vector<int>>&res , vector<int>&t )
{
	int N = inD.size(); 

	if( t.size() == N )
	{
		res.push_back(t);
		return ;
	}

	for( int u = 0 ; u < N ; u++ )
	{
		if(inD[u] == 0 )
		{
			
			t.push_back(u);
			inD[u]-- ;

			for( auto v : g[u] )
			{
				inD[v]--;
			}


			rec( inD , g , res , t );

			for( auto v : g[u] )
			{
				inD[v]++;
			}
			t.pop_back();
			inD[u]++;
		}
	}
}

vector< vector<int> > f( int N , vector< vector<int>>&E )
{
	vector<int>g[N];
	vector<int>inD(N,0);
	for( auto x : E )
	{
		int a = x[0];
		int b = x[1];
		a--;
		b--;
		g[a].push_back(b);
		inD[b]++;
	}

	vector< vector<int> > res ;
	vector< int > t ;
	rec( inD , g , res , t );

	return res ;
}


int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    vector< vector<int> > E ;
    E.push_back({ 4 , 2 });
    E.push_back({ 5 , 2 });
    E.push_back({ 3 , 1 });
    E.push_back({ 2 , 1 });

    auto res = f( 5 , E ) ;

   	// cout<<res.size()<<endl;
   	for( auto x : res )
   	{
   		for( auto i : x )
   			cout<<i+1<<" ";
   		cout<<endl;
   	}
    
    return 0;
}
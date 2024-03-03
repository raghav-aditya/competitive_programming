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


bool dfs( vector<int>&A , int have , int T , int mx_ , vector<int>&vis )
{
	if( have > mx_ || have < 0 || vis[have] == 1 )
		return 0 ;

	vis[have] = 1 ;

	if( have == T )
		return 1 ;

	for( auto a : A )
	{
		if( dfs( A , have-a , T , mx_ , vis ) || dfs( A , have+a, T , mx_ , vis ) )
			return 1 ;
	}

	return 0 ;
}

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector< int > jug = { 999911 , 999913 };
    int sum = 1 ;

    int mx_ = accumulate( all(jug) , 0LL );

    if( sum > mx_ || sum < 0 )
    {
    	cout<<"NOT POSSIBLE"<<endl;
    }

    vector< int > vis(mx_+1 , 0 );

    if(dfs( jug , 0 , sum , mx_ , vis ))
    {
    	cout<<"POSSIBLE"<<endl;
    }
    else
    {
    	cout<<"NOT POSSIBLE"<<endl;
    }

    return 0;
}
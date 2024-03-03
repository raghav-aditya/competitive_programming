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


// int ok[k+1][k+1];

set< ar > ok ;
int t[100][5][5];
int go( int S , int first , int last )
{
	int32_t i = S ;
	int32_t j = first ;
	int32_t k = last ;


	if( S < 0 )
		return 0 ;

	if( S == 0 )
	{
		if(ok.count({last,first}))
			return 1;
		return 0 ;
	}

	if(t[i][j][k] != -1 )
		return t[i][j][k] ;

	if(first==-1)
	{
		return t[i][j][k] = 
		go( S-1 , 1 , 1 ) +
		go( S-2 , 2 , 2 ) + 
		go( S-3 , 3 , 3 ) ;
	}

	if( last == 1 )
		return t[i][j][k] = go( S-2 , first , 2 ) + go( S-3 , first , 3 );
	else if( last == 2 )
		return t[i][j][k] = go( S-1 , first , 1 ) + go( S-2 , first , 2 );
	else 
		return t[i][j][k] = go( S-1 , first , 1 );
}

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    auto solve = [&]()->void
    {
    	ok.insert({1,2});
    	ok.insert({1,3});
    	ok.insert({2,1});
    	ok.insert({2,2});
    	ok.insert({3,1});
    	memset( t , -1 , sizeof t );
        cout<<go( 12 , -1 , -1 )<<endl;
    };
    

     solve();
    
    return 0;
}
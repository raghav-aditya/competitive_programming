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
#define oo (int)pow(2L,60)
#define arr array<int,3> 
#define ar array<int,2>

/********** GO DOWN ***********/

/* 
   If the genius trains just as hard.... 
   what chance do I have to beat him? 
*/

int dp[100010][110];
int prefix[100010][110];

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	// memset( dp , 0 , sizeof dp );
	// memset( prefix , 0 , sizeof prefix );


	auto solve = [&]()->void
	{
		 
		int N , K ;
		cin>>N>>K ;
		vector<int>A(N); for( auto &x : A ) cin>>x ;
		vector<int>B(K); iota(all(B),1);

		for( int i = 0 ; i < N ; i++ )
		{	dp[i][0] = 0 ;
			prefix[i][0] = 0 ;
			for( int j = 1 ; j <= K ; j++ )
			{
				dp[i][j] = -oo ;
				prefix[i][j] = -oo ;
			} 
		}

		dp[0][1] = A[0]*B[0] ;
		prefix[0][1] = dp[0][1] ; 


		for( int i = 1 ; i < N ; i++ )
		for( int j = 1 ; j <= K ; j++ )
		{
			dp[i][j] = max( prefix[i-1][j-1] , dp[i-1][j] ) + A[i]*B[j-1];
			dp[i][j] = max( dp[i][j] , -oo );
			prefix[i][j] = max( prefix[i-1][j] , dp[i][j] );
		}

		int res = INT_MIN ;
		for( int i = 0 ; i < N ; i++ )
			res = max( res , dp[i][K] );
		cout<<res<<endl;

	};
	

		
    int test = 1 ;
	cin>>test;
	while(test--)
	solve();
	
	return 0;
}
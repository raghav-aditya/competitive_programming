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

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	auto solve = [&]()->void
	{
		int N , k ;
		cin>>N>>k ;
		k++;

		vector< int > A(N);
		for( auto &x : A )cin>>x ;
		deque< int > q ;

		vector< int > dp(N,0);

		int res = INT_MAX ;

		if( k > N )
		{
			cout<<0<<endl;
			return ;
		}

		auto dis = [&]( int i , int j )->int 
		{
			return abs(i-j+1) ;
		};

		for( int i = 0 ; i < N ; i++ )
		{
			dp[i] = A[i];

			while(q.size() && dis(i,q.front()) > k+1 ) q.pop_front();

			if(q.size() && i >=k )
			dp[i] += dp[q.front()];

			while(q.size()&&dp[i]<=dp[q.back()])q.pop_back();

			q.push_back(i);

			if(dis(N-1,i)<=k)
				res = min( res , dp[i]);
		}
		cout<<res<<endl;
	};
	

		
    int test = 1 ;
	cin>>test;
	while(test--)
	solve();
	
	return 0;
}

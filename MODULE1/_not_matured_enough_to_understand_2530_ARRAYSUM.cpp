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


class seg_tree
{
	vector<int> T ;
	int N ;
public:
	seg_tree(int size)
	{
		this->N = size ;
		T.resize(2*N,0);
	}

	void update(int p , int x)
	{
		assert(p<N&&p>=0);
		for( T[p+=N] = x ; p >>= 1 ; )
		{
			T[p] = T[p<<1] + T[p<<1|1] ;
		}
	}

	int get( int a , int b )
	{
		if(a>b)
		return 0;
		b = min( b , N-1 );
		int res = 0 ;
		assert( a < N && b < N );
		for( a += N , b += N+1 ; a < b ; a >>= 1 , b >>= 1 )
		{
			if(a&1) res += T[a++];
			if(b&1) res += T[--b];
		}
		return res ;
	}
};

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	auto solve = [&]()->void
	{
		int N , M ;
		cin>>N>>M ; vector<int>A(N),B(M);
		for( auto &x : A )cin>>x ;
		for( auto &x : B )cin>>x ;

		int dp[N][M];
		memset( dp , 0 , sizeof dp );

		set< int > _set(all(A));
		vector<int> rank( all(_set) );

		vector< seg_tree > st ;
		for( int i = 0 ; i < M ; i++ )
		{
			seg_tree t(N);
			st.push_back(t);
		}

		for( int i = 0 ; i < N ; i++ )
		{
			dp[i][0] = 1 ;
			int curr = lower_bound( all(rank) , A[i] ) - rank.begin() ;
			st[0].update( curr , 1 );
		}

		for( int i = 0 ; i < N ; i++ )
		for( int j = 1 ; j < M ; j++ )
		{
			int curr = lower_bound( all(rank) , A[i]+B[j] ) - rank.begin() ;
			int lst  = upper_bound( all(rank) , A[i]+B[j-1]) - rank.begin() - 1 ;

			dp[i][j] = st[j-1].get(0,lst);
			st[j].update(curr,dp[i][j]);
		}


		for( int i = 0 ; i < N ; i++ )
		{
			for( int j = 0 ; j < M ; j++ )
				cout<<dp[i][j]<<" ";
			cout<<endl;
		}
	};
	

		
    int test = 1 ;
	// cin>>test;
	while(test--)
	solve();
	
	return 0;
}
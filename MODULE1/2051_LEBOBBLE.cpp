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
	int N ;
	vector<int>T;
public:
	seg_tree( int size) 
	{
		this->N = size ;
		T.resize(2*N);
	}

	int get( int a , int b )
	{
		int res = 0 ;
		for( a+=N , b+=N+1 ;  a < b ; a >>= 1 , b >>= 1 )
		{
			if(a&1) res += T[a++];
			if(b&1) res += T[--b];
		}
		return res ;
	}

	void update( int p , int x )
	{
		for( T[p+=N] +=x ; p >>= 1 ; )
			T[p] = T[p<<1] + T[p<<1|1];
	}
};

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	auto solve = [&]()->void
	{
		int N , b ;
		cin>>N>>b ;

		vector< int > g ;  
		vector< int > A(N);
		for( auto &x : A )
		{
			cin>>x ;
			g.push_back(x);
			g.push_back(x+b);
		}

		vector<int>P(N);
		for( auto &x: P )cin>>x ;
		sort( all(g) );

		auto rank = [&]( int x ) -> int 
		{
			return lower_bound( all(g) , x ) - g.begin();
		};


		seg_tree st(g.size());
		int res = 0 ;
		for( int i = N-1 ; i >= 0 ; i-- )
		{
			res += P[i] * st.get( 0 , rank(A[i]+b) - 1 );
			res += (100-P[i]) * st.get( 0 , rank(A[i]) - 1 );

			st.update( rank(A[i]+b) , P[i] );
			st.update( rank(A[i]) , 100-P[i] );
		}

		double ans = res ;
		ans /= 10000 ;
		cout<<fixed<<setprecision(4)<<ans<<endl;
	};
	

		
    int test = 1 ;
	cin>>test;
	while(test--)
	solve();
	
	return 0;
}
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


class seg_tree
{
	vector< ar > T ;
	int N ;

	ar pull( ar a , ar b )
	{
		return { a[0] + b[0] , a[1] + b[1] };
	}

public:
	seg_tree( int size )
	{
		this->N = size ;
		T.resize( 2*N );

		T[N] = { N , N };

		for( int i = N-1 ; i > 0 ; i-- )
			T[i] = pull( T[2*i] , T[2*i+1] );
	}

	ar get( int a , int b )
	{
		ar res = { 0 , 0 };
		for( a += N , b += N+1 ; a < b ; a >>= 1 , b >>= 1 )
		{
			if(a&1) res = pull( res , T[a++] );
			if(b&1) res = pull( T[--b] , res ); 
		}
		return res ;
	}

	void update( int p , int x , int y )
	{
		ar v = { x , y };
		p += N ;
		T[p] = pull( T[p] , v ) ;
		for( ; p>>=1 ; )
		{
			T[p] = pull( T[2*p] , T[2*p+1] );
		}
	}
};




class DSU
{
	vector< int > par ;
	vector< int > size ;
	int N ;

public:

	DSU( int sz )
	{
		this->N = sz ;
		par.resize(N,0);
		iota(all(par),0);
		size.resize(N,1);
	}

	int find( int x )
	{
		if( par[x] == x )
			return x ;
		return par[x] = find( par[x] );
	}

	int get( int x )
	{
		return size[find(x)] ;
	}

	void join( int a , int b )
	{
		if( find(a) == find(b) )
			return ;
		int L = get(a) ;
		int R = get(b) ;
		par[a] = find(b);
		size[find(a)] = L + R ;
	}
};

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	auto solve = [&]()->void
	{
		int N ;cin>>N ;
		vector<int>A(N); for( auto &x : A )cin>>x ;

		int res = 0 ;
		seg_tree st(N); // my segment tree 
		DSU tool(N); // my dsu tool 

		unordered_map< int , vector< int > > where ;

		for( int i = 0 ; i < N-1 ; i++ )
			where[abs(A[i]-A[i+1])].push_back(i);


		auto pos = [&]( int x )->int 
		{
			return x-1 ;
		};


		// we only care about the diff [ 0 , N ] 
		// we will enumerate for all the diff 

		for( int L = 0 ; L <= N ; L++ )
		{
			for( auto k : where[L] )
			{
				int a = k ;
				int b = k+1 ;

				int left = tool.get(a);
				int right= tool.get(b);

				st.update( pos(left) , -left , -1 );
				st.update( pos(right), -right, -1 );

				tool.join(a,b);
				int big = tool.get(a);
				st.update( pos(big) , big , 1 );
			}

			int sum = 0 ;
			int times = 0 ;

			if( L == 0 ) // we dont care about zero length array 
				continue ;

			auto node = st.get( pos(L) , N-1 );
			sum = node[0];
			times = node[1];

			// for[sum( x - L + 1 )] = sum(x) - (L-1) * times  

			int here = sum - times*(L-1);
			res += here ;
		}
		cout<<res<<endl;

	};
	

		
    int test = 1 ;
	cin>>test;
	while(test--)
	solve();
	
	return 0;
}
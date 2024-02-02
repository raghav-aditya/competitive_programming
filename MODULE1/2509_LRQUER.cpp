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

class node
{
	
public:

	multiset<int>mst ;

	int near_left(int k)
	{
		if(mst.size()==0)
			return -1;
		auto it = mst.lower_bound(k);

		if(it==mst.begin())
			return -1;
		it--;
		return *it ;
	}
	int near_right(int k)
	{
		if(mst.size()==0)
			return pow(2L,40);

		auto it = mst.lower_bound(k);
		if( it != mst.end() )
			return *it ;
		return pow(2l,40);
	}
	void insert(int x)
	{
		mst.insert(x);
	}
	void erase( int x )
	{
		mst.erase(mst.find(x));
	}
};

class seg_tree
{
	vector< node > T ;
	int N ;
	vector< int > A ;

	node pull( node a , node b )
	{
		node g ;
		for( auto &x : a.mst )g.insert(x);
		for( auto &x : b.mst )g.insert(x);
		return g ;
	}

public:


	int at(int p)
	{
		return A[p];
	}

	seg_tree(const vector<int>&A_ )
	{
		this->N = A_.size() ;
		T.resize(2*N);
		this->A = A_;

		for( int i = 0 ; i < N ; i++ )
			T[i+N].insert(A_[i]);

		for( int i = N-1 ; i > 0 ; i-- )
			T[i] = pull( T[i<<1] , T[i<<1|1] );
	}

	void update( int p , int x )
	{
		int old = A[p];
		A[p] = x ;
		for( p+=N ; p >= 1; p>>=1 )
		{
			T[p].erase(old);
			T[p].insert(x);
		}
	}

	int near_left( int a , int b , int k )
	{
		int res = 0 ;
		for( a += N , b += N+1 ; a < b ; a >>=1  , b >>=1 )
		{
			if( a&1 ) res = max( res , T[a++].near_left(k) );
			if( b&1 ) res = max( T[--b].near_left(k) , res ); 
		}
		return res ;
	}

	int near_right( int a , int b , int k )
	{
		int res = pow(2L,40);
		for( a += N , b += N+1 ; a < b ; a >>= 1 , b >>= 1 )
		{
			if(a&1) res = min( res , T[a++].near_right(k) );
			if(b&1) res = min( T[--b].near_right(k) , res );
		}
		return res;
	}
};


int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	auto solve = [&]()->void
	{
		int N , Q ;
		cin>>N>>Q ;
		vector<int>A(N);
		for( auto &x : A )cin>>x ;

		seg_tree st(A);

		auto func = [&]( int a , int b , int m ) -> int 
		{
			if( m >= 1 && m <= pow(10L,9) )
			{
				return (m-a)*(b-m);
			}
			else
				return 0;
		};

		for( int q = 0 ; q < Q ; q++ )
		{
			int type ;
			cin>>type ;

			if( type == 1 )
			{
				int l , r ;
				cin>>l>>r ;
				l--;r--;
				int a = st.at(l); 
				int b = st.at(r);
				int k = (a+b)>>1 ;

				int res = 0 ;


				for( int del = -1 ; del <= 1 ; del++ )
				{
					int nk = k + del ;

					res = max( res , func(a,b,st.near_left(l,r,nk)) );
					res = max( res , func(a,b,st.near_right(l,r,nk)) );
				}

				cout<<res<<endl;
			}
			else
			{
				int p , x ;
				cin>>p>>x ; p-- ;
				st.update(p,x);
			}
		}
	};
	

		
    int test = 1 ;
	cin>>test;
	while(test--)
	solve();
	
	return 0;
}
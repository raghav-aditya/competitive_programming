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
	vector<ar>T;
	int N ;
public:

	seg_tree( int size )
	{
		this->N = size ;
		T.resize(2*N);
	}

	void update( int p , int x )
	{
		for( T[p+N][0] = T[p+N][1] = x , p += N ; p >>= 1 ; )
		{
			T[p][0] = min( T[2*p][0] , T[2*p+1][0] );
			T[p][1] = max( T[2*p][1] , T[2*p+1][1] ); 
		}
	}

	int get_min( int a , int b )
	{
		int res = INT_MAX ;
		for( a += N , b += N+1 ; a < b ; a >>= 1 , b >>= 1 )
		{
			if(a&1) res = min( res , T[a++][0] );
			if(b&1) res = min( res , T[--b][0] );
		}
		return res ;
	}

	int get_max( int a , int b )
	{
		int res = INT_MIN ;

		for( a += N , b += N+1 ; a < b ; a >>= 1 , b >>= 1 )
		{
			if(a&1) res = max( res , T[a++][1] );
			if(b&1) res = max( res , T[--b][1] );
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
		int N ;
		cin>>N ;

		vector< ar > A( N );
		for( auto &x : A )cin>>x[0]>>x[1];

		seg_tree st1(N) , st2(N) ;

		for( int i = 0 ; i < N ; i++ )
		{
			int a = A[i][0] + A[i][1] ;
			int b = A[i][0] - A[i][1] ;

			st1.update(i,a);
			st2.update(i,b);
		}

		int Q ;
		cin>>Q ;

		for( int q = 0 ; q < Q ; q++ )
		{
			string type ;
			cin>>type;
			if( type == "U" )
			{
				int p , x , y ;
				cin>>p>>x>>y ;
				int a = x+y ;
				int b = x-y ;

				st1.update(p,a);
				st2.update(p,b);
			}
			else
			{
				int l , r ; cin>>l>>r ;
				cout<<max( st1.get_max(l,r) - st1.get_min(l,r)
						,  st2.get_max(l,r) - st2.get_min(l,r))<<endl;
			}
		}
	};
	
    int test = 1 ;
	// cin>>test;
	while(test--)
	solve();
	
	return 0;
}
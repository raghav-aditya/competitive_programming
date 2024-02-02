#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define all(x) begin(x) , end(x) 
#define ar array<int,2>

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
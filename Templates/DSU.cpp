
#include <bits/stdc++.h>
using namespace  std ;

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
		iota( par.begin() , par.end() ,0);
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
		if( is_same( a, b) )
			return ;
		
		int L = get(a) ;
		int R = get(b) ;

		if( L > R )
		{
			swap( L , R );
			swap( a , b );
		}

		par[find(a)] = find(b);
		size[find(a)] = L + R ;
	}

    bool is_same( int a , int b )
    {
        if( find(find(a)) == find(find(b)) )
        return 1 ;

        return 0 ;
    }
};	
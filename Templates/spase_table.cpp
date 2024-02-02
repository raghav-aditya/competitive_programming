#include <bits/stdc++.h>
using namespace std ;

class sparse_table
{
	int K ;
	vector< vector<int> > T ;
	int N ;

	void build( const vector<int>&A )
	{
		for( int i = 0 ; i < N ; i++ )
			T[i][0] = A[i] ;

		for( int L = 1 ; L < K ; L++ )
		for( int i = 0 ; i < N ; i++ )
		{
			T[i][L] = T[i][L-1] ;

			int dis = 1<<(L-1);
			if(i+dis>=N)
				continue ;
			T[i][L] = min( T[i][L-1] , T[i+dis][L-1] );
		}
	}

public:
	sparse_table( const vector<int>&A )
	{
		this->N = A.size();
		this->K = log2(N) + 1 ;
		vector< vector< int > > temp( N+1 , vector<int>(K+1,INT_MAX) );
		this->T = temp ;

		build( A );
	}

	int get( int a , int b )
	{
		int len = b-a+1 ;
		int L = log2(len);
		int dis = 1<<L ;
		return min( T[a][L] , T[b-dis+1][L] );
	}
};
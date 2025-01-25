#include <bits/stdc++.h>
using namespace std ;

// PURQ ( point update range query )

class seg_tree
{
	vector<int>T ;
	int N ;

	int join( int a , int b )
	{
		return a + b ;
	}

public:

	seg_tree( const vector<int>&A )
	{	
		this->N = A.size();
		T.resize(2*N);

		for( int i = 0 ; i < N ; i++ )
			T[i+N] = A[i];

		for( int i = N-1 ; i > 0 ; i-- )
			T[i] = join( T[i<<1] , T[i<<1|1] );
	}

	int update( int p , int x )
	{
		for( T[p+=N] = x ; p >> 1 ; )
			T[p] = join( T[p<<1] , T[p<<1|1] );
	}

	int sum( int a , int b )
	{
		int res = 0 ; 
		for( a += N , b += N+1 ; a < b ; a >>= 1 , b >>= 1 )
		{
			if( a&1 ) res = join( res, T[a++]);
			if( b&1 ) res = join( T[--b] , res );
		}
		return res;
	}
};
























// RUPQ ( range update point query )



class seg_tree_1
{
public:
    vector< int > T ;
    int N ;
    seg_tree_1( vector< int > A )
    {
        N = A.size();
        T.resize(2*N);
        for( int i = 0 ; i < N ; i++ )
            T[i+N] = A[i];
    }

    void update( int a , int b , int x )
    {
        for( a += N , b += N+1 ; a < b ; a >>= 1 , b >>= 1 )
        {
            if(a&1) T[a++] += x ;
            if(b&1) T[--b] += x ;
        }
    }

    int get( int p )
    {
        int res = 0 ;
        for( p+=N ; p > 0 ; p>>=1 )
            res += T[p] ;
        return res ;
    }

    void push()
    {
    	for( int i = 1 ; i < N ; i++ )
    	{
    		T[2*i] += T[i] ;
    		T[2*i+1|1] += T[i] ;
    		T[i] = 0 ;
    	}
    	// now T[i+N] -> updated A[i] 
    }
};
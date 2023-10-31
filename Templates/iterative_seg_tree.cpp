#include <bits/stdc++.h>
using namespace std ;

// PURQ ( point update range query )

class segTree_1
{
public:
	vector<int>T ;
	int N ;

	segTree(vector<int>A)
	{
		N = A.size();
		T.resize(2*N);
		for( int i = 0 ; i < N ; i++ )
			T[i+N] = A[i];

		for( int i = N-1 ; i > 0 ; i-- )
			T[i] = T[i<<1] + T[i<<1|1];
	}

	void update( int p , int x )
	{
		for( T[p+=N] = x ; p > 1 ; p-- )
			T[p<<1] = T[p] + T[p^1] ;
	}

	int sum( int a , int b )
	{
		int res = 0 ;
		for( a += N , b += N+1 ;  a < b ; a >>= 1 , b >>= 1 )
		{
			if(a&1) res += T[a++];
			if(b&1) res += T[--b];
		}
		return res ;
	}

};
























// RUPQ ( range update point query )



class segTree_2
{
public:
    vector< int > T ;
    int N ;
    segTree( vector< int > A )
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
    		T[i<<1] += T[i] ;
    		T[i<<1|1] += T[i] ;
    		T[i] = 0 ;
    	}

    	// now T[i+N] -> updated A[i] 
    }


};
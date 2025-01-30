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




// non commuatative commbiner function : cses subarray sum queries:


struct node
{
    int sf=0 , pf=0 , mx=0  , sum=0 ;
    node(){};
    node(int x){
        sf = pf = mx = sum = x ;
    }
};

class seg_tree
{
    vector<node>T ;
    int N ;

    node join( node a , node b )
    {
        node res ;
        res.pf = max( a.pf , a.sum + b.pf );
        res.sf = max( b.sf , b.sum + a.sf );
        res.mx = max({a.mx , b.mx , a.sf + b.pf });
        res.sum = a.sum + b.sum ;
        return res ;
    }
public:

    seg_tree( vector<int>A )
    {
        this->N = A.size();
        T.resize(2*N);

        for( int i = 0 ; i < N ; i++ )
            T[i+N] = node(A[i]);

        for( int i = N-1 ; i > 0 ; i-- )
            T[i] = join( T[2*i] , T[2*i+1] );
    }

    void update( int p , int x )
    {
        for( T[p+=N] = node(x) ; p >>= 1 ; )
            T[p] = join( T[2*p] , T[2*p+1] );
    }

    int get( int a , int b ){
        node L(0),R(0) ;
        for(a+=N,b+=N+1;a < b ; a >>= 1 , b >>= 1 )
        {
            if(a&1) L = join( L , T[a++] );
            if(b&1) R = join( T[--b] , R );
        }
        return join(L,R).mx ;
    }

};

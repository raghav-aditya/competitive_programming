/*

	Iterative PURQ ( point update range query )


	void init( vector< int > A )
	{
		for( int i = 0 ; i < N ; i++ )
		T[i+N] = A[i];

		for( int i = N-1 ; i > 0 ; i-- )
		T[i] = T[i<<1] + T[i<<1|1] ;
	}

	int query( int a , int b )
	{
		int sum = 0 ;
		for( a += N , b += N+1 ; a < b ; a >>= 1 , b >>= 1 )
		{
			if(a&1)	sum += T[a++] ;
			if(b&1) sum += T[--b] ;
		}
		return sum ;
	}

	void update( int p , int x )
	{
		for( T[p+=N] += x ; p > 1 ; p >>= 1 )
		T[p>>1] = T[p] + T[p^1] ; 
	}




*/



/*

	Iterative RUPQ ( range update point query )

	void init( vector<int> A )
	{
		for( int i = 0 ; i < N ; i++ )
		T[i+N] = A[i] ;
	}

	void update( int a , int b , int x , int N ) // add a element on range 
	{
		for( a += N , b += N+1 ; a < b ; a >>= 1 , b >>= 1 )
		{
			if(a&1) T[a++] += x ;
			if(b&1) T[--b] += x ;
		}
	}

	int query( int p , int N )
	{
		int res = 0 ;
		for( p += N ; p > 0 ; p >>= 1 )
		res += T[p] ;
		return res ;
	}
	void push( int N ) 
	{
		for( int i = 1 ; i < N ; i++ ){
			T[i<<1] += T[i] ;
			T[i<<1|1] += T[i] ;
			T[i] = 0 ;
		}
	}  

*/













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








int T[1000000];

	void update( int a , int b , int x , int N ) // add a element on range 
	{
		for( a += N , b += N+1 ; a < b ; a >>= 1 , b >>= 1 )
		{
			if(a&1) T[a++] += x ;
			if(b&1) T[--b] += x ;
		}
	}

	int query( int p , int N )
	{
		int res = 0 ;
		for( p += N ; p > 0 ; p >>= 1 )
		res += T[p] ;
		return res ;
	}



	void push( int N ) // push all the pending updates to childrens 
	{
		for( int i = 1 ; i < N ; i++ ){
			T[i<<1] += T[i] ;
			T[i<<1|1] += T[i] ;
			T[i] = 0 ;
		}
	}








int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	


	vector< int > A = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 };
	int N = A.size();


	for( int i = 0 ; i < N ; i++ )
		T[i+N] = A[i] ;

	update( 0 , 3 , 5 , N );

	update( 6 , 8 , 7 , N ) ;




	
	return 0;
}
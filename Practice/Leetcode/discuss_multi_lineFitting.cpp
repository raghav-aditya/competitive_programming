#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) begin(x) , end(x) 
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
vector<int> fact( int N = MAX )
{
	vector<int>f(N,1);
	for( int i = 2 ; i < N ; i++ )f[i] = (i*f[i-1])%mod;
	return f ;
}


/********** GO DOWN ***********/

/* 
   If the genius trains just as hard.... 
   what chance do I have to beat him? 
*/


// #define int long long

double solve( vector< array<int , 2 > >&A , double C )
{
	int N = A.size();
	sort( A.begin() , A.end() );
	
	long long presum[N+1][5];
	memset( presum , 0 , sizeof presum );

	for( int i = 0 ; i < N ; i++ )
	{
		presum[i+1][0] = presum[i][0] + A[i][0] ; // sum( x ) 
		presum[i+1][1] = presum[i][1] + A[i][1] ; // sum( y )
		presum[i+1][2] = presum[i][2] + A[i][0]*A[i][0]; // sum( x^2 )
		presum[i+1][3] = presum[i][3] + A[i][1]*A[i][0];// sum( x*y )
		presum[i+1][4] = presum[i][4] + A[i][1]*A[i][1]; // sum( y^2 )
	}

	auto range_cost = [&]( int st, int en )->double 
	{
		// 0 based 
		int L = en-st+1 ; // lenfth of this range 
		if( L == 1 || L == 2 ) // we can always make line pass through less than two points without doing fitting 
			return 0 ;

		long double sum_x = 1.00000*(presum[en+1][0] - presum[st][0]) ;
		long double sum_y = 1.00000*(presum[en+1][1] - presum[st][1]) ;
		long double sum_x2 = 1.00000*(presum[en+1][2] - presum[st][2]) ; 
		long double sum_xy = 1.00000*(presum[en+1][3] - presum[st][3]) ;
		long double sum_y2 = 1.00000*(presum[en+1][4]  -presum[st][4]) ;

		long double a =  (L*(sum_xy) - sum_x*sum_y) / ( L*sum_x2 - pow(sum_x,2) );
		long double b =  (sum_y - a*sum_x) / ( L );

		// cost of range = expand summation( ax_b-y )^2  
		// all the terms involved in expansion is precalculated above

		long double cost = pow(a,2)*sum_x2 + L*pow(b,2) + sum_y2 + 2*a*b*( sum_x - sum_y ) - 2*a*sum_xy ;
		return abs(cost) ; // cost is positive as it is square of a number 

		// all this trouble for to compute a , b for range dynamically and there cost for range in O(1)
	};



	double T[N];
	memset( T , 0 , sizeof T );

	for( int j = 0 ; j < N ; j++ )
	{
		T[j] = range_cost(0,j) + C*1 ;
		for( int i = 1 ;  i <= j ; i++ )
		{
			// [ 0 , i-1 ]  + [ i , j ] 
			double left_cost = T[i-1];
			double new_cost = left_cost + range_cost( i , j ) +  C ;

			T[j] = min( T[j] , new_cost );
		}
	}
	return T[N-1];
}

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	
	vector< array< int , 2 > > A = { 
		{ 0 , 1 },
		{ 1 , 2 },
		{ 2 , 3 },
		{ 5 , 5 }
	};

	cout<<solve( A , 3 )<<endl;
	return 0;
}
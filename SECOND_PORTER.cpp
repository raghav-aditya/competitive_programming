/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long 

/*

Given an m x n integer matrix matrix, if an element is 0, 
set its entire row and column to 0's.

Example 1 - 
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

	

		1 1 1        1 0 1 
		1 0 1   ->   0 0 0 
		1 1 1        1 0 1



------------------------------------

int M * N ;

int M = rows
int N = colums 

R[N] -> state of column
C[M] -> state of row 

------------------------------------------

bool first_row = 1, where there is zero in first row  ;
	 first_row = 0, R[j] -> 0 , in result it will zero only ,


bool first_colum = 1 ,
		
		 111011   -> 0000000
		 111011   
		 111111	
			

*/


void solve( vector<vector<int>>&A ){

	int M = A.size();
	int N = A[0].size();

	bool first_row = 0 ;
	bool first_column = 0 ;

	for( int j = 0 ; j < N ; j++ )
		first_row |= A[0][j] == 0 ; 

	for( int i = 0 ; i < M ; i++ )
		first_column |= A[i][0] == 0 ;


	for( int i = 1 ; i < M ; i++ )
	for( int j = 1 ; j < N ; j++ )
	{
		if( A[i][j] == 0 )
		{
			A[0][j] = 0 ;
			A[i][0] = 0 ;
		}
	}


	for( int i = 1 ; i < M ; i++ )
	for( int j = 1 ; j < N ; j++ )
	{
		if( A[i][0] == 0 || A[0][j] == 0 )
			A[i][j] = 0 ;
	}


	if(first_row)
	{
		for( int j = 0 ; j < N ; j++ )
			A[0][j] = 0 ;
	}	

	if(first_column)
	{
		for( int i = 0 ; i < M ; i++ )
			A[i][0] = 0 ;
	}

	for( int i = 0 ; i < M ; i++ )
	{
		for( int j = 0 ; j < N ; j++ )
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}


    return ;
}

int32_t main() {

  vector< vector<int> > A =
  {
  		{ 1 } ,
  		{ 0 }
  };

  solve(A);

return 0;
}   
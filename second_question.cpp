/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 


You are given an integer array height of length n. 
There are n vertical lines drawn such that the two endpoints of
 the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, 
such that the container contains the most water.
Return the maximum amount of water a container can store.


height = [1,8,6,2,5,4,8,3,7]
			1             8

			L = 8 
			l_h = 7 
			water = L * l_h = 8*7 = 56 



	6                       10  ---> [  ]


FIXED = S = a * b 

A.M >= GM

a == b 



[ 1 , 2 , 3 , 1 ]

  i           j ---> 4 
      i       j ---> 3 

      i   j     ---> 4 

------------------

[ 1 , 2 , 3 , 1 ]

  i           j ---> 4 

  i       j    ----> 3 
  	  i   j    ----> 4 



[ 20 , 7 , 20[1] , 100 , 20 ]  --->

  i                     j    ---> 24 * 1 = 24 
	  i                 j    ---> 23 * 2 = 46
      i            j         ---> 22 * 7 =
		   i                 ---> 21 * 1 = 21 , 20 , 19 , 18.....
  




------------------------------------

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){


	// vector<int> A = { 1,8,6,2,5,4,8,3,7}; 
	vector<int> A = 
	// { 0 , 2 , 0 , 4 , 0 , 3 };
	// { 0, 0, 5, 0, 6} ;
	{ 0 , 0 , 0 , 0 };



	int N = A.size();

	int res = 0 ;

	for( int i = 0 ; i < N ; i++ )
	for( int j = i+1 ; j < N ; j++ )
	{
		int L = j-i;
		int lower_h = min( A[i] , A[j] );

		// cout<<i<<" "<<j<<" "<<lower_h*L<<endl;
		

		res = max( res , lower_h * L );

	}

	cout<<res<<endl;






	// height  * length 

	int i = 0 ;
	int j = N-1 ;

	int best = 0 ; // best choice 

	while( i < j )
	{
		int low_h = min( A[i] , A[j] );  
		int L = j-i ;

		int local_res = low_h*L ;

		best = max( best , local_res );


		if( A[i] < A[j] )
			i++;
		else if( A[i] >= A[j] ) 
			j--;
		// else
		// {
		// 	int f = rand();
		// 	if(f%2)
		// 		i++;
		// 	else
		// 		j--;
		// }


	}

	cout<<best<<endl;






    return ;
}

int32_t main() {

  solve();

return 0;
}   
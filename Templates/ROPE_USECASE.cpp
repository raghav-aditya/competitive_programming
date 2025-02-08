/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/
#include <bits/stdc++.h>
using namespace std;

#include <ext/rope>
using namespace __gnu_cxx ;

// link to artical: https://codeforces.com/blog/entry/107434

int32_t main() {
  
	vector<int>B = { 0,1,2,3,4,5,6,7,8,9 };
               vector< vector<int> > Q = 
               {{0,9},{2,4},{1,3}};


               // reverse the subarray for each query
     int N = B.size();

     auto get_rev_index = [&]( int i )->int
     {
     		return (2*N - 1 - i) ;
     };

     auto get_len = [&]( int i , int j )-> int {
     	return j-i+1 ;
     };

     rope < int > A ;
   
   	 for( auto x : B )
   	 	A.push_back(x);
   	 for( int i = N-1 ; i >= 0 ; i-- )
   	 	A.push_back(A[i]);

   	 for( auto x : Q )
   	 {
   	 	int a = x[0];
   	 	int b = x[1];

   	 	int ra = get_rev_index(a);
   	 	int rb = get_rev_index(b);

   	 	// [0,a-1] [ a, b] [b+1 , rb-1 ] [ rb, ra ] [ ra+1 , 2*N-1] ;
   	 		 // 1 2 3 4 5 
   	 		 // 1 4 3 2 5 
   	 	auto one = A.substr(0,get_len(0,a));
   	 	auto two = A.substr(a,get_len(a,b));
   	 	auto three = A.substr(b+1,get_len(b+1,rb-1));
   	 	auto four = A.substr(rb,get_len(rb,ra));
   	 	auto five = A.substr(ra+1,get_len(ra+1,2*N-1));
   	 	A = one + four + three + two + five ;
   	 }

   	 for( auto x : A ){
   	 	if(N<=0)
   	 	{
   	 		break;
   	 	}
   	 	cout<<x<<" ";
   	 	N--;
   	 }

     return 0 ;
}   
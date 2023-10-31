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


int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	auto solve = [&]()->void
	{
		
		int N , K ;
		cin>>N>>K ;
		vector< int > A( N );
		for( auto &x : A )cin>>x ; 
		sort( A.begin() , A.end() );

		int dp[K+1][1<<(N+2)];
		memset( dp , 0 , sizeof dp );

		dp[0][0] =  1 ;

		int tot = accumulate( A.begin() , A.end() , 0 );
		int avg = tot / K ;

		if( tot % K || avg < A.back() )
		{
			cout<<"no"<<endl;
			return ;
		}

		for( int k = 0 ; k < K ; k++ )
		{
			for( int subset = 0 ; subset < mask(N) ; subset++ )
			{
				if(!dp[k][subset])continue ;

				int sum = 0 ;

				for( int i = 0 ; i < N ; i++ )
				{
					if(subset & mask(i))
						sum += A[i] ;
				}

				sum -= k*avg ;


				for( int i = 0 ; i < N ; i++ )
				{
					if( subset & mask(i) )continue ;

					if( sum + A[i] == avg )
						dp[k+1][subset | mask(i)] = 1 ;
					else if( sum + A[i] < avg )
						dp[k][subset | mask(i)] = 1 ;
				}
			}
		}

		if(dp[K][mask(N)-1])
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;

	};
	

		
    int test = 1 ;
	cin>>test;
	while(test--)
	solve();
	
	return 0;
}




/*

RESOURCES: 


People have done two solution where one is true dp using bitmask other one 
is counting number of disjoint subsets with sum = total(A[i])/K , if that number
is greater than K we can always make the solutions.

This problem is quite educational in the sense that we are defining the DP state which is not the exact
but some range type like we are saying dp[k][mask] = true ;

means that , the subset which is represented by mask will be able to split into k set's with sum avg or k-1 set with 
sum avg and the last one sum < avg 

so our state is in the range. i got to know something new that dp states can be in dangling situation.( not exactly defined )





soln: 


1. 
	This solution does something cool:
	https://www.codechef.com/viewsolution/35451551
2.
	This solution does counting of disjoints sets
	https://www.codechef.com/viewsolution/10986219
3.
	This Problem from leetcode look very similar revisit this problem( K = 2 obviously )
	https://leetcode.com/problems/tallest-billboard/description/






*/
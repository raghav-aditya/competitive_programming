/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) begin(x) , end(x) 

/********** GO DOWN ***********/

/* 
   If the genius trains just as hard.... 
   what chance do I have to beat him? 
*/


class Hash
{
	 string A ;
	 int mod = pow(10,9)+7 ;
	 vector< int > P ;
	 vector< int > t ;
	 int N ;
	 int base ;


	public:

		Hash(){}
		Hash( int base_ , string A_ )
		{
			A = A_ ;
			N = A.size();
			base = base_ ;

			P.resize( N+1 , 0 );
			t.resize( N+1 , 1 );

			for( int i = 1 ; i <= N ; i++ )
			{
				t[i] = base*t[i-1];
				t[i] %= mod ;
			}


			for( int i = 1 ; i <= N ; i++ )
			{
				P[i] = P[i-1] + A[i]*t[i];
				P[i] %= mod ;
			}
		}


		int get( int a , int b )
		{
			return ((P[b+1] - P[a]) + mod) % mod ; 
		}


		int task( int i )
		{
			int j = i+1;
			int k = j+1 ;

			int org = get( 0 , N-1 );
			int L = i+1 ; // correct 

			int rem = A[i]*t[L] + A[j]*t[L+1] + A[k]*t[L+2] ;
			int add = A[j]*t[L] + A[k]*t[L+1] + A[i]*t[L+2] ;

			int fin = org - rem + add ;
			fin %= mod ;
			fin += mod ;
			fin %= mod ;

			return fin ;
		}


};



int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    auto solve = [&]()->void
    {
    	int N ;
    	cin>>N ;
    	string A ;
    	cin>>A ;

    	int L = 3 ;

    	srand(time(0));

    	vector< int > PP = {100003,100019};
    	int k = PP.size();
    	Hash tool[PP.size()];
    	unordered_set< int > st[PP.size()];

    	for( int i = 0 ; i < k ; i++ )
    	{
    		Hash tt( PP[i] , A );
    		tool[i] = tt ;
    	}

    	int res = 0 ;

    	for( int i = 0 ; i+L-1 < N ; i++ )
    	{
    		for( int j = 0 ; j < k ; j++ )
    		{
    			st[j].insert(tool[j].task(i));

    			res = max( res , (int)st[j].size() );
    		}
    	}
    	cout<<res<<endl;
    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
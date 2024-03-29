/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x) , end(x) 

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void
    {

    	int N ;
    	cin>>N ;
    	string A ;
    	cin>>A ;	


    	string res(N,'0');
    	vector< int > R , P , S ;

    	for( int i = 0 ; i < N ; i++ )
    	{
    		if( A[i] == 'R' )
    		{
    			R.push_back(i);
    		}
    		else if ( A[i] == 'P' )
    		{
    			P.push_back(i);
    		}
    		else
    		{
    			S.push_back(i);
    		}
    	}


    	for( int i = N-1 ; i >= 0 ; i-- )
    	{
    		auto x = A[i];

    		if( x == 'R' )
    		{
    			auto it = lower_bound( all(P) , i ) ;
    			if( it == P.end() ) res[i] = x ;
    			else
    				res[i] = res[*it];
    		}
    		else if ( x == 'P' )
    		{
    			auto it = lower_bound( all(S) , i ) ;
    			if( it == S.end() ) res[i] = x ;
    			else
    				res[i] = res[*it];
    		}
    		else
    		{
    			auto it = lower_bound( all(R) , i ) ;
    			if( it == R.end() ) res[i] = x ;
    			else
    				res[i] = res[*it];
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
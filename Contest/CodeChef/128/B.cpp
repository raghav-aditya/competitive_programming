/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void{
        int N ;
        cin>>N ;

        vector<int>A(N);
        for( auto &x : A )cin>>x;

        int H = pow(10LL,16) ;
    	int L =  0 ;
    	
    	for( int i = 1 ; i < N; i++)
    	{
    		if( A[i] < A[i-1] )
    		{
    			if( i+1 < N )
    			H = min( A[i+1]-A[i] , H );
    			L = max( L , A[i-1] - A[i] );
    			i++;
    		}
    	}

    	if( L > H )
    	{
    		cout<<"NO"<<endl;
    		return ;
    	}
    	cout<<"YES"<<endl;
    };
    

int test = 1 ;
cin>>test;
while(test--)
solve();
return 0;
}   
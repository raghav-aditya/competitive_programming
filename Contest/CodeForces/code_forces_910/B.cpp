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
#define vi vector<int>
#define vvi vector<vi>
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
#define oo (int)pow(2L,60)
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
    
    auto work = [&]( int a , int b)->arr 
    {
    	int k = (a - 2*b) / b ;

    	int p = a - 2*b ;
    	int q = b ;

    	arr v1 ;

		int n = a - k*b ;
		int first = n - n/2 ;
		int second = n - first ;
		 v1 = { first , second , k };
		 	
		 if(p%q==0)
		 	return v1 ;



		 k++;
		 n = a - k*b ;
		 first = n - n/2 ;
		 second = n - first ;
		 arr v2 = { first , second , k };


		 if( first < 1 || second < 1 || second > n || first > n )
		 	return v1 ;
		 return v2 ;
    };

    auto solve = [&]()->void
    {
        int N ;
        cin>>N ;
        vector<int>A(N); for( auto &x : A )cin>>x ;

        int res = 0 ;
        if( N == 1 )
        {
        	cout<<0<<endl;
        	return ;
        }

        int drop = 0 ; 
        for( int i = N-2 ; i >= 0 ; i-- )
        {
        	if( drop )
        	{
        		res += A[i]-1 ;
        		continue ;
        	}

        	if( A[i] > A[i+1] )
        	{
        		res++;
        		int a = A[i] ;
        		int b = A[i+1];
        		int second = min( b , a - (a/2) );
        		int first = a-second ;

        		a = first ;
        		b = second ;

        		if( first == 1 ){
        			drop = 1 ;
        		}

        			A[i] = first ;
        			A[i+1] = second ;

        			if( A[i] > A[i+1] )
        			{
        				arr it = work( a , b );
        				res += it[2] ;

        				A[i] = it[0] ;
        				A[i+1] = it[1];
        				i++;
        			}
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
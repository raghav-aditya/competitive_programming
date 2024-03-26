/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) begin(x) , end(x) 
#define on(i) (1LL << (i) )
#define mask(i) (on(i)-1)
#define vi vector<int>
#define vvi vector<vi>
#define arr array<int,3> 
#define ar array<int,2>

const int mod = pow(10,9)+7 ;
const int MAX = pow(10,5)+1 ;
const int dx[8] = { 1 , -1 , 0 , 0 , 1 , 1 , -1 , -1 } ;
const int dy[8] = { 0 , 0 , 1 , -1 , 1 , -1 , 1 , -1 } ;
int mod_pow( int a , int b ){if( a == 0 || a == 1 ) return a ; if( b == 0 )return 1 ; int ha = mod_pow( a , b/2 ); ha *= ha; ha %= mod ; if( b&1 ) ha *= a ; return ha%mod;}
int inverse( int a )
{
    return mod_pow(a,mod-2);
}


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
        
    	int N , k ;
    	cin>>N>>k ;
    	vector<int>A(N);

    	for( auto &x : A )cin>>x ;	

    	int mx = *max_element( A.begin() , A.end() );

    	auto check = [&]( int m , int i , int v )->bool{

    		int res = INT_MIN ;
    		int need = 0 ;

    		for( int j = i ; j >= 0 ; j-- )
    		{
    			int to_make = v ;
    			int curr = A[j] ;

    			if( curr > to_make )
    				break;
    			int del = to_make - A[j] ;

    			if( need + del > k )
    				break ;

    			need += del; 

    			res = max( res , to_make );

    			if( res >= m )
    				return 1 ;
    			v++;
    		}

    		return res ;
    	};

    	auto ok = [&]( int m )-> bool{
    		for( int i = N-1 ; i >= 0 ; i-- )
    		{	
    			if(check(i,A[i]))
    				return 1 ;
    		}
    		return 0 ;
    	};


        int l = mx ;
        int h = pow(10LL,16);

        while( l < h )
        {
        	int m = (l+h)>>1 ;

        	if(ok(m))
        		l = m+1;
        	else
        		h = m-1;
        }

        for( int m = l+1 ; m >= l-1 ; m-- )
        {
        	if( m >= mx && ok(m) )
        	{
        		cout<<m<<endl;
        		return ;
        	}
        }

        cout<<"Incorrect bounds"<<endl;
    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}



// 6 5 4 1 5
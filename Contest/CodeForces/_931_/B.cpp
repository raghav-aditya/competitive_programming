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
    

	vector<int> A = { 1 , 3 , 6 , 10 , 15 };
    

	int S = 3*6*10*15 ;
	int N = A.size();
 
 	vector< vector<int> > t(N+1, vector<int>(S+1,0));

	for( int i = 0 ; i <= N ; i++ )
	for( int j = 0 ; j <= S ; j++ )
		t[i][j] = INT_MAX ;

	for( int i = 0 ; i <= N ; i++ )t[i][0] = 0 ;
	

	for( int i = 1 ; i <= N ; i++ )
	for( int j = 1 ; j <= S ; j++ )
	{
		if( j >= A[i-1] )
		{
			t[i][j] = min( t[i-1][j] , 1 + t[i][j-A[i-1]] );
		}
		else
			t[i][j] = t[i-1][j] ;
	}


    auto solve = [&]()->void
    {

    	int T ;
    	cin>>T ;

    	int res = INT_MAX ;

    	for( int k = S-100; k <= S ; k++ )
    	{
    		int extra = t[N][k]*(T/k) ;
    		int nT = T%k ;

    		res = min( res , extra + t[N][nT] );
    	}

    	cout<<res<<endl;



    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
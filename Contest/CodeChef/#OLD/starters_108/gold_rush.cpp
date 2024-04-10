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
    

    auto solve = [&]()->void
    {
		int M , N ;
		cin>>M>>N ;

		if( M == 1 && N == 1 )
		{
			cout<<1<<endl;
			return ;
		}

		int res = 0 ;
		int prev = 0;
		int total = 0;


		for( int k = 2 ; k <= max( M , N ) ; k++ )
		{
			vvi dp( M , vi(N,0));
			auto H = dp ;
			auto V = dp ;	
			
			for( int i = 0 ; i < M ; i++ )
			{
				dp[i][0] = (i<k) ;
				V[i][0]  = (i+1)<k ;
				H[i][0]  = (i<k) ;
			}	

			for( int j = 0 ; j < N ; j++ )
			{
				dp[0][j] = (j<k);
				H[0][j]  = (j+1)<k;
				V[0][j]  = (j<k);
			}



			for( int i = 1 ; i < M ; i++ )
			for( int j = 1 ; j < N ; j++ )
			{
				H[i][j] = V[i][j] = dp[i][j] = (V[i-1][j] + H[i][j-1])%mod ;

				if( i -(k-1) >= 0 )
					V[i][j] = (V[i][j]-H[i-(k-1)][j-1] + mod)%mod ;

				if( j -(k-1) >= 0 )
					H[i][j] = (H[i][j]-V[i-1][j-(k-1)] + mod)%mod ; 
			}


			int ways_with_k = (dp[M-1][N-1]-prev+mod)%mod ;
			
			prev = dp[M-1][N-1];
			res += k*ways_with_k ;
			total += ways_with_k ;

			total %= mod ;
			res %= mod ;
		}

		cout<<(res * inverse(total))%mod<<endl; ;


    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
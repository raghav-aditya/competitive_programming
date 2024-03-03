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


class Solution{

    vector<vector<int>>dp ;
    int go( int M , int N )
    {
        if( M == 1 )
        return N ;
        
        if( N == 1 )
        return M ;
        
        if( M == N )
        return 1 ;
        
        if( dp[M][N] != -1 )
        return dp[M][N];
        
        int H = INT_MAX ;
        int V = INT_MAX ;
        
        for( int i = 1 ; i <= M/2 ; i++ )
        {
            H = min(go( i , N ) + go( M-i , N ), H );
        }
        
        for( int j = 1 ; j <= N/2 ; j++ )
        {
            V = min(V , go( M , j ) + go( M , N-j ) );
        }
        
        return dp[M][N] = min( H , V );        
    }

	public:
	int minCut(int M, int N)
	{
        vector<vector<int>>t(M+1,vector<int>(N+1,-1));
        dp = t ;
        return go( M , N );
	}
};

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Solution st ;
    cout<<st.minCut( 13 , 11 )<<endl;
    
    return 0;
}
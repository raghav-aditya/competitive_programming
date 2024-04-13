/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353 ;

int ways[5001][5001];
int dp[5001][5001];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N ;
    cin>>N ;
    vector<int>A(N);
    for( auto &x : A )cin>>x ;
    int S = accumulate(A.begin(),A.end(),0LL);
    
    for( int i = 0 ; i <= N ; i++ )
    for( int j = 0 ; j <= S ; j++ )
        ways[i][j] = dp[i][j] = 0 ;

    sort(A.begin() , A.end());
    for( int i = 0 ; i <= N ; i++ )
    ways[i][0] = 1 ;

    for( int i = 1 ; i <= N ; i++ )
    for( int j = 1 ; j <= S ; j++ )
    {
        int v = A[i-1];
        ways[i][j] += ways[i-1][j];
        ways[i][j] %= mod ;
        
        if( j >= v )
            ways[i][j] += ways[i-1][j-v] ;

        ways[i][j] %=mod ;
    }        

    for( int i = 1 ; i <= N ; i++ )
    for( int j = 1 ; j <= S ; j++ )
    {
        int v = A[i-1];

        dp[i][j] += dp[i-1][j]; // not choosing me 
        dp[i][j] %= mod ;

        int cost = max( (j+1)/2 , v );

        if( j >= v ){ // chossing me 
            dp[i][j] += (ways[i-1][j-v]*cost)%mod ;
            dp[i][j] %= mod ;
        }
        dp[i][j] %= mod ;
    }

    int res = 0 ;

    for( int j = 0 ; j <= S ; j++ )
    {
        res += dp[N][j];
        res %= mod ;
    }

    cout<<res<<endl;
    

return 0;
}   
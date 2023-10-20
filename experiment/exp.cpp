#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) begin(x) , end(x) 
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
vector<int> fact( int N = MAX )
{
	vector<int>f(N,1);
	for( int i = 2 ; i < N ; i++ )f[i] = (i*f[i-1])%mod;
	return f ;
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
        int N ;
        cin>>N ;
        vector<int>A(N) ;
        
        for( auto &x : A )cin>>x ;
        vector<int>f(N,1),b(N,1);
        
        vector<int>res ;
        for( int i = 0 ; i < N ; i++ )
        {
            auto x = A[i];
            auto it = lower_bound( res.begin() , res.end() , x ) ;
            if( it == res.end() )
            res.push_back(x);
            else
            *it = x ;
            
            f[i] = res.size();
        }
        
        vector< int > k ;
        
        res = k ;
        int mx = 1 ;
        
        for( int i = N-1 ; i >= 0 ; i-- )
        {
            int x = A[i] ;
            auto it = lower_bound( res.begin() , res.end() , -x );
            
            if( it == res.end() )
            res.push_back(-x);
            else
            *it = -x ;
            
            b[i] = res.size();

            mx = max( mx , f[i] + b[i] );
            mx = min( mx , N );
        }
        
        cout<<mx<<endl;
        // for( auto x : f )
        // 	cout<<x<<" ";
        // cout<<endl;
        // for( auto x : b )
        // 	cout<<x<<" ";
        // cout<<endl;
        // cout<<endl;
	};
	
	
	
	
	
	
	
	
    int test = 1 ;
	cin>>test;
	while(test--)
	solve();
	
	return 0;
}


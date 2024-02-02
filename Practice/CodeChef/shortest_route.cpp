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
        int N , M ;
        cin>>N>>M ;
        
        vector<int>A(N),B(M);
        for( auto &x: A )cin>>x ;
        for( auto &x: B )cin>>x ;

        vector<int>f ,b ;
    	for( int i = 0 ; i < N ; i++ )
    	{
    		if( A[i] ==  1 )
    			f.push_back(i+1);
    		else if( A[i] == 2 )
    			b.push_back(i+1);
    	}


    	for( auto x : B )
    	{
    		if( x == 1 )
    			cout<<0<<endl;
    		else
    		{
    			int res = N ;

    			int k = lower_bound( all(f) , x ) - f.begin();

    			for( int d = -1 ; f.size() && d <= 0 ; d++ )
    			{
    				int p = k + d ;
    				if( p < 0 || p >= (int)f.size() || f[p] > x )
    					continue ;

    				int diff = abs( f[p] - x );
    				res = min( res , diff );
    			}

    			k =  lower_bound( all(b) , x ) - b.begin();

    			if( k >= 0 && k < (int)b.size() && b.size() && b[k] >= x )
    				res = min( res , abs(x-b[k]));

    			if(res == N )
    				cout<<-1<<" ";
    			else
    				cout<<res<<" ";
    		}
    	}
    	cout<<endl;
        
	};
	
	
	
	
	
	
	
	
    int test = 1 ;
	cin>>test;
	while(test--)
	solve();
	
	return 0;
}
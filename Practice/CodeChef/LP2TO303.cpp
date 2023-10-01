/*
https://www.codechef.com/practice/LP2TO303/problems/SNTEMPLE?tab=statement
*/ 
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
	    cin>>N;
	    vector<int>A(N);
	    for( auto &x : A )cin>>x ;


	    auto ok = [&]( int m )->bool 
		{
		 	vector<int>f(N,0);
		 	vector<int>b(N,0);

		 	f[0] = 1 ;
		 	b[N-1] = 1 ;

		 	for( int i = 1 ; i < N ; i++ )
		 	f[i] = min( 1+f[i-1] , A[i] );

		 	for( int i = N-2 ; i >= 0 ; i-- )
		 	b[i] = min( 1+b[i+1] , A[i] );

		 	int mx = 1 ;
		 	for( int i = 0 ; i < N ; i++ )
		 		mx = max( mx , min( f[i] , b[i] ) );

		 	return mx >= m ;
		};

		auto clean = [&]( int k )->int
		{
			for( int m = k+1 ; m >= k-1 ; m-- ){
				if( m >= 1 && m < pow(10,9) && ok(m))
					return m;
			}	
				return k;
		};


	    int l = 1 ;
		int h = pow(10,9);

		while( l < h )
		{
			int m = (l+h)>>1 ;
			if( ok(m) )
				l = m+1 ;
			else
				h = m-1 ;
		}

		int k = clean(l);
		int s = k*(k+1) - k ;

		int sum = accumulate( A.begin() , A.end() , 0LL );
		cout<<sum-s<<endl;

	};
	
	
	
	
	
	
	
	
    int test = 1 ;
	cin>>test;
	while(test--)
	solve();
	
	return 0;
}
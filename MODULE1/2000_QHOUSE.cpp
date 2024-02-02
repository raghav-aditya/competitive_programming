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

	auto in = [&]( int x , int y )-> bool 
	{
		cout<<"? "<<x<<" "<<y<<endl;
		string A ;
		cin>>A ;
		return A == "YES" ; 
	};
	
	auto H = [&]( int y )
	{
		int l = 0 ; 
		int h = 1000;

		while( l < h )
		{
			int m = (l+h)>>1 ;
			if(in(m,y))
				l = m+1;
			else
				h = m-1;
		}

		for( int m = l+1 ; m >= l-1 ; m-- )
		{
			if( m >=0 && m <= 1000 && in(y,m))
				return m ;
		}
		return l ;
	};

	auto V = [&]( int x )
	{
		int l = 0 ;
		int h = 1000 ;

		while( l < h )
		{
			int m = (l+h)>>1 ;
			if(in(x,m))
				l = m+1;
			else
				h = m-1;
		}

		for( int m = l+1 ; m >= l-1 ; m-- )
		{
			if( m <= 1000 && m >= 0 && in(x,m) )
				return m;
		}
		return l ;
	};

	auto solve = [&]()->void
	{
		int half_a = H(0);
		int height = V(0);
		int c = H(2*half_a);

		int side = 2*half_a ;
		int tHeight = height - side ;
		int base = 2 * c ;

		int sq = side * side ;
		int tr = base * tHeight ;
		tr >>= 1 ;

		int total = sq + tr ;
		cout<<"! "<<total<<endl;
	};
	

		
    int test = 1 ;
	// cin>>test;
	while(test--)
	solve();
	
	return 0;
}

// Not Tested 
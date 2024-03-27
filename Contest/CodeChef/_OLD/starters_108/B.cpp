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
		int N ;
		cin>>N ;
		vector<int>A(N) ;
		
		for( auto &x : A )cin>>x ;

		map< int , vector<int> > pos ;


		for( int i = 0 ; i < N ; i++ )
		{
			pos[A[i]].push_back(i) ;
		}

		if(pos.size()==1)
		{
			auto it = *pos.begin();
			cout<<it.first<<" "<<0<<endl;
			return  ;
		}


		int res = INT_MAX ;
		int who = -1 ;

		for( auto it : pos )
		{
			auto v = it.second ;
			int g = 0;

			if(v[0]!=0)
			g = max( g , 2*v[0] );

			for( int j = 1 ; j < (int)v.size() ; j++ )
			{
				g = max( g , v[j]-v[j-1] );
			}

			if(v.back()!=N-1)
			g = max( g , 2*(N-1 - v.back()) );

			int k = max( 1LL , g/2 );

			if(res > k )
			{
				res = k ;
				who = it.first ;
			}
		}

		cout<<who<<" "<<res<<endl;
	};
	

		
    int test = 1 ;
	cin>>test;
	while(test--)
	solve();
	
	return 0;
}
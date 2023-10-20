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
#define arr array<int,3> 
#define ar array<int,2>

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

vector< ar > factorise( int N )
{
	vector< ar > res ;
	for( int f = 2 ; f*f <= N ; f++ )
	{
		int cnt = 0;
		while(N%f)
		{
			cnt++;
			N /= f;
		}

		if(cnt)
			res.push_back({f,cnt});
	}

	if(N!=1)
		res.push_back({N,1});
	return res ;
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
	

	vector< vector< int > > f(10*MAX);
	for( int i = 2 ; i*i < MAX ; i++ )
	{
		if(f[i].size()==0)
		for( int j = i ; j < 10*MAX ; j += i )
			f[j].push_back(i);
	}

	auto solve = [&]()->void
	{
		int N ;
		cin>>N ;
		vector< int > A( N );
		for( auto &x : A )cin>>x ;

		vector<int>t(N,1);

		unordered_map< int , vector< int > > mp ;

		for( auto x : f[A[0]] )
			mp[x].push_back(0);

		int res = 1 ; 
		for( int i = 1 ; i < N ; i++ )
		{
			auto ff = f[A[i]];
			int c = -1 ;

			for( auto x : ff )
			{
				if(mp[x].size())
					c = max( c , mp[x].back() );
				mp[x].push_back(i);
			}

			t[i] = min( t[i-1] + 1 , i - c );
			res = max( res , t[i] );
		}

		if( res > 1 )
		cout<<res<<endl;
		else
		cout<<-1<<endl;		
			
	};
	

		
    int test = 1 ;
	cin>>test;
	while(test--)
	solve();
	
	return 0;
}


// array 
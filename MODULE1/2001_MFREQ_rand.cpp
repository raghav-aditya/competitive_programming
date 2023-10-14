/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
mt19937 mt ;
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
	

	auto solve = [&]()->void
	{
		int N , Q ;
		cin>>N>>Q ;

		vector< int > A(N);
		for( auto &x : A )cin>>x ;

		vector< int > f( N , 1 ) , b( N , 1 );

		for( int i = 1 ; i < N ; i++ )
		if( A[i] == A[i-1] )
			f[i] = 1 + f[i-1];
		
		for( int i = N-2 ; i >= 0 ; i-- )
		if( A[i] == A[i+1] )
			b[i] = 1 + b[i+1];

		for( int q = 0 ; q < Q ; q++ )
		{
			int L , R , k ;
			cin>>L>>R>>k ;
			L--;
			R--;
			int len = R-L+1;
			int found = 0 ;
			for( int tries = 0 ; !found && tries <= 50 ; tries++ )
			{
				int in = L + (mt()%len);
				int front = min( f[in] , in-L+1 );
				int back = min( b[in] , R-in+1 );
				if( front + back - 1 >= k )
				{
					found = 1 ;
					cout<<A[in]<<endl;
					break ;
				}
			}

			if(!found)
				cout<<-1<<endl;
			
		}

	};
	

		
    int test = 1 ;
	// cin>>test;
	while(test--)
	solve();
	
	return 0;
}
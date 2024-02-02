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

class seg_tree
{
	vector<int>T;
	int N ;
public:
	seg_tree( const vector<int>&A )
	{
		this->N = A.size();
		T.resize(2*N,0);
		for( int i = 0 ; i < N ; i++ )
			T[i+N] = A[i];
		for( int i = N-1 ; i > 0 ; i-- )
			T[i] =  T[2*i] ^ T[2*i+1] ;
	}

	void update( int p , int x )
	{
		for( T[p+=N] = x ; p >>= 1 ; )
		{
			T[p] = ( T[p<<1] ^ T[p<<1|1] ) ;
		}
	}

	int get( int a , int b )
	{
		int res = 0 ;
		for( a += N , b += N+1 ; a < b ; a >>= 1 , b >>= 1 )
		{
			if(a&1) res = ( res ^ T[a++] );
			if(b&1) res = ( res ^ T[--b] );
		}
		return res;
	}

};

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	auto solve = [&]()->void
	{
		int N , Q ;
		cin>>N>>Q ;
		vector<int>A(N); for( auto &x : A )cin>>x ;

		seg_tree st(A);

		for( int q = 0 ; q < Q ; q++ )
		{
			int a , b ;
			cin>>a>>b ;
			
				a--;b--;
				cout<<st.get(a,b)<<endl;
		}

	};
	

		
    int test = 1 ;
	// cin>>test;
	while(test--)
	solve();
	
	return 0;
}
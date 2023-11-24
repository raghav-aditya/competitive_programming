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

class seg_tree
{
	vector<ar>T ;
	int N ;

	ar pull( ar a , ar b )
	{
		int mn = min( a[0] , b[0] );
		int mx = max( a[1] , b[1] ) ;

		return { mn , mx };
	}
public:
	seg_tree( const vector<int>&A )
	{
		this->N = A.size();
		T.resize(2*N);

		for( int i = 0 ; i < N ; i++ )
			T[i+N] = { A[i] , A[i] } ;
		for( int i = N-1 ; i > 0 ; i-- )
			T[i] = pull( T[2*i] , T[2*i+1] );
	}

	ar get( int a , int b )
	{
		ar res = { INT_MAX , INT_MIN } ;

		for( a += N , b += N+1 ; a < b ; a >>= 1 , b >>= 1 )
		{
			if(a&1) res = pull( res , T[a++] );
			if(b&1) res = pull( res , T[--b] );
		}
		return res ;
	}
};

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    auto solve = [&]()->void
    {
        int N ;
        cin>>N ;
       	vector<int>A(N) , B = A ;

       	for( auto &x : A )cin>>x ;
       	for( auto &x : B )cin>>x ;
       	int res = 0 ;

       	vector<int>t(N),p(N);
        for( int i = 0 ; i < N ; i++ )
        {
        	t[i] = -2*(A[i] - B[i]) ;
        	res += abs( A[i] - B[i] );
        }

        sort( all(A) );
        sort( all(B) );
        sort( all(t) );

        int del = 0 ;

        del = max( del ,  B.back() - 2*A.front() );


        del = max( del , t.back() );

        res += max( 0LL , del ) ;

        cout<<res<<endl;
    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
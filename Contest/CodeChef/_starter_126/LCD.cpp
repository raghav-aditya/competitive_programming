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



vector<int>P = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
set<int>set_prime( P.begin() , P.end() );

int get( int N )
{
	int b = 0 ;
	
	for( auto x : P )
	{
		if( N%x == 0 )
			b = b|(1LL<<x) ;
	}
	return b ;
}


vector< map< int , int  > > dp ;


int go( vector<int>&A , int i , int g , int k )
{
	int first = (g&-g) ;

	if( dp[i].find(first) != dp[i].end() )
	return dp[i][first] ;

	if(!(first&g))
		return dp[i][first] = 0 ;
	
	int N = A.size();
	if( i == N )
		return first == k ;

	int res = go( A , i+1 , g , k );
	int v = A[i];
	int g_ = (v&g) ;

	if( v != 0 )
	res += go( A , i+1 , g_ , k );

	return dp[i][first] = res ;
	
}

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    auto solve = [&]()->void
    {
        int N , k ;
        cin>>N>>k ;
        vector<int>A(N);
        for( auto &x : A )cin>>x ;


        if(set_prime.count(k)==0)
        {
        	cout<<0<<endl;
        }
        else
        {
        	for( auto &x : A )
        		x = get( x );

        	vector< map< int , int  > > tt( N+1 );
        	dp = tt ;

        	int full = (1LL<<60)-1;
        	int my = get( k );
        	cout<<go( A , 0 , full , my )<<endl;
        }
    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
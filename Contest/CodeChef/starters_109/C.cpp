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


bool done( vector<ar>A , vector<ar>B )
{
	unordered_map< int , multiset< int > > bag1 , bag2 , bag3 ;
	for( auto x : A )
	{
		int a = x[0];
		int c = x[1];
		bag1[c].insert(a);
		bag3[c].insert(a);
	}

	for( auto x : B )
	{
		int a = x[0] ;
		int c = x[1] ;
		bag2[c].insert(a);
		bag3[c].insert(a);
	}


	int N = A.size();
	int last = -1 ;

	for( int i = 0 ; i < N ; i++ )
	{
		int col = A[i][1] ;

		if( bag2[col].size()==0)
		{
			continue;
		}
		else
		{
			auto it = lower_bound( all(bag3[col]) , last );

			if( it != bag3[col].end() )
			{
				auto new_val = *it ;
				bag3[col].erase(bag3[col].find(new_val));
				A[i][0] = new_val ;
			}
		}

		last = A[i][0] ;
	}
	for( int i = 1 ; i < N ; i++ ){
		if( A[i] < A[i-1] )
			return 0 ;
	}
		return 1 ;
}

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    auto solve = [&]()->void
    {

        int N ;
        cin>>N ;
        vector<ar>A(N);
        vector<ar>B(N);


        for( int i = 0 ; i < N ; i++ )
        	cin>>A[i][0] ;

        for( int i = 0 ; i < N ; i++ )
        	cin>>A[i][1] ;

        for( int i = 0 ; i < N ; i++ )
        	cin>>B[i][0] ;
        for( int i = 0 ; i < N ; i++ )
        	cin>>B[i][1];



        if( done( A , B ) )
        	cout<<"Yes"<<endl;
        else
        	cout<<"No"<<endl;
    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
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


class solution {

int N , M , k_ ;
string A ;


int solve( int i , int k )
{
	if( i == N )
		return k == 1 ; // when i go outside i should i have 1 piece left 

	if( k <= 0 )  // can move around when number of peice is less than 1 
		return 0 ;

	if( A[i] == '1' )
		return 0 ; // can't start new substring with 1 

	int res = 0 ;

	for( int j = i+M-1; j < N ; j++ )
	{
		if( A[j] == '1' ) // can end with '1' here 
		res += solve( j+1 , k-1 );
	}

	return res;
}

public:

	solution(){}

	void input(){
		cin>>N>>M>>k_ ;
		cin>>A ;
	}

	void task(){

		for( auto &x : A )
		{
			int v = x-'0';
			if( v&1 )
				x = '1';
			else
				x = '0';
		}

		print( solve( 0 , k_ ));
	}


	void print( int res ){
		cout<<res<<endl;
	}

};



















int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution my_solution ;

    my_solution.input();
    my_solution.task();

    return 0;
}


/*

9 2 3 
454569421


N=9, M=2, K=3, S=’454569421′

*/
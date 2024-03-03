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

// /********** GO DOWN ***********/

// /* 
//    If the genius trains just as hard.... 
//    what chance do I have to beat him? 
// */

class T
{
public:

	int id = 0 ;
	string data ;
	vector< T* > childs ;

	T(){};

	T( string data_ )
	{
		this->data = data_ ;
	}

	void add( T* x )
	{
		childs.push_back(x);
	}
};

void dfs( string &A , vector<int>&who , T* root )
{
	if( root == nullptr )
		return  ;
	int id = root->id ;
	if(root->childs.size()==0)
	{
		for( auto x : root->data ){
			A += x ;
			who.push_back(id);
		}
	}
	for( auto x : root->childs )
		dfs( A , who , x );
}

vector<int> f( T* root , string P )
{
	vector<int>who;
	string A ;
	dfs( A , who , root );

	// KMP
	string B = P + "#" + A ;
	int M = A.size();
	int N = B.size();

	vector<int>lps(N,0);
	int i = 1;
	int len = 0;

	while( i < N )
	{
		if( B[i] == B[len] )
			lps[i++] = ++len ;

		else
		{
			if(len == 0 )
				lps[i++] = 0;
			else
				len = lps[len-1];
		}
	}

	vector< int >res ;

	for( int i = M+1 ; i < N ; i++ )
	{
		if( lps[i] == M )
		{
			int st = i-M-1 ;
			int en = i ;

			set<int>my_set( who.begin() + st , who.begin() + i + 1);

			for( auto x : my_set )
				res.push_back(x);

			break;
		}
	}
	return res;
}

int32_t main()
{

	// 

	return 0 ;
}
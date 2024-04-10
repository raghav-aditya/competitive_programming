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

class T
{
public:
	int st , en ;
	T* left = nullptr ;
	T* right = nullptr;
	int del = 0 ;
	vector<int> A ;

	T( int st_ , int en_ )
	{
		this->st = st_ ;
		this->en = en_ ;
	}
};

class seg_tree
{
public:
	seg_tree( const vector<int>&A )
	{
		root = build( 0 , A.size()-1 , A );
	}

private:
	T* root = nullptr ;

	void pull( T* node)
	{
		vector<int>k;
		if(node->left)
		{
			for( auto &x : node->left->A )
				k.push_back(x);
		}
		if(node->right)
		{
			for( auto &x : node->right->A )
				k.push_back(x);
		}
		sort(all(k));
		node->A = k ;
	}


	T* build( int st , int en , const vector<int>&A )
	{
		if( st > en )return nullptr ;

		T* node = new T(st,en);

		if( st == en )
		{
			node->del = 0 ;
			node->A.push_back(A[st]);
		}
		else
		{
			int mid = (st+en)>>1 ;

			node->left = build( st , mid , A );
			node->right = build( mid+1,en, A );

			pull(node);
		}

		return node ;
	}

	int get( T* node , int l , int r , int add )
	{
		if( node == nullptr || l > r || node->st > r || node->en < l )
			return 0 ;
		if( l <= node->st && node->en <= r )
		{
			auto k = node->A ;
			return k.end() - lower_bound(all(k),add);
		}
		else
		{
			return get( node->left , l , r , add + node->del ) + get( node->right , l , r , add + node->del );
		}
	}

	void update( T* node , int l , int r , int k )
	{
		if( node == nullptr || l > r || node->st > r || node->en < l || k == 0 )
			return ;

		if( l <= node->st && node->en <= r )
		{
			node->del += k ;
			return ;
		}
		else
		{
			update( node->left , l , r , k );
			update( node->right, l , r , k );
		}
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
		vector<int>A(N);
		for( auto &x : A )
			cin>>x ;
		
		
	};
	

		
    int test = 1 ;
	cin>>test;
	while(test--)
	solve();
	
	return 0;
}
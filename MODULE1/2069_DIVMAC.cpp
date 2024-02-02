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

#define arr array<int,3> 
#define ar array<int,2>

/********** GO DOWN ***********/

/* 
   If the genius trains just as hard.... 
   what chance do I have to beat him? 
*/

int till = 1000010;
vector< int > lpf(till,1) ;

class T 
{
public:
	T* left = nullptr ;
	T* right = nullptr;
	int pf = 0 ;
	int mx = 0 ; 
	int st = 0 ;
	int en = -1;
	T( int st_ , int en_ )
	{
		this->st = st_ ;
		this->en = en_ ;
	}
};


class seg_tree
{

public:
	seg_tree( const vector< int > &A )
	{
		root = build( 0 , A.size()-1 , A );
	}
	void update( int l , int r )
	{
		return update(root, l , r );
	}
	int get( int l , int r )
	{
		return get( root , l , r );
	}

private:

	// we will not use push as queris uses work degenerated work reduction 

 	T* root = nullptr ;
 	T* build( int st , int en , const vector<int>&A )
 	{
 		if( st > en ) return nullptr ;
 		T *node = new T( st , en );
 		if( st == en )
 		{
 			node->pf = lpf[A[st]];
 			node->mx = A[st] ;
 		}
 		else
 		{
 			int mid = (st+en)>>1 ;
 			node->left = build(st,mid,A);
 			node->right= build(mid+1,en,A);
 			pull(node);
 		}
 		return node ;
 	}

 	void update( T* node , int l , int r )
 	{
 		// node->mx = 1 , is the smart move, early termination
 		if( !node || r < node->st || node->en < l || node->mx == 1 ) 
 			return ;
 		if( node->st == node->en )
 		{
 			node->mx /= node->pf ;
 			node->pf = lpf[node->mx];
 			return ;
 		}
 		else
 		{
 			update(node->left, l , r);
 			update(node->right,l , r);
 			pull(node);
 		}
 	}

 	int get( T* node , int l , int r )
 	{
 		if( !node || node->en < l || r < node->st )
 			return -1 ;
 		if( l <= node->st && node->en <= r )
 			return node->pf ;
 		return max(get(node->left,l,r) , get(node->right,l,r));
 	}

 	// mx - > max_val remaining value 
 	// spf- > biggest smallest prime factor 
 	void pull(T*node)
 	{
 		int spf = 0 ;
 		int mx_ = 0 ;

 		if(node->left){
 			mx_ = max( mx_ , node->left->mx );
 			spf = max( spf , node->left->pf );
 		}
 		if(node->right){
 			spf = max( spf , node->right->pf);
 			mx_ = max( mx_ , node->right->mx);
 		}
 		node->pf = spf ;
 		node->mx = mx_ ;
 	}
};


int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	

	for( int i = 2 ; i < till ; i++ )
		if( lpf[i] == 1 )
		for( int j = i ; j < till ; j += i )
		if(lpf[j]==1)lpf[j] = i ;



	auto solve = [&]() -> void
	{	
		int N , M ; 
		cin>>N>>M ;
		vector<int>A(N);
		for( auto &x: A )cin>>x ;
		seg_tree st(A);

		for( int i = 0 ; i < M ; i++ )
		{
			int t , l , r ;
			cin>>t>>l>>r ; 
			l--; r--;
			if(!t)
				st.update(l,r);
			else
				cout<<st.get(l,r)<<" ";
		}
		cout<<endl;
	};


    int test = 1 ;
	cin>>test;
	while(test--)
	solve();
	
	return 0;
}
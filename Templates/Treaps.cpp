#include <bits/stdc++.h>
using namespace std ;

mt19937 mt ;

class T
{
public:
	char x ;
	int prior = mt()%INT_MAX;
	int size = 0 ;
	T* left = nullptr ;
	T* right = nullptr ;

	T( char x_ )
	{
		this->x = x_;
		size = 1 ;
	}
};


int getSize(T*x){ return x ? x->size : 0 ; };


void pull( T* x )
{
	if( x == nullptr )
		return ;
	x->size = 1 + getSize(x->left) + getSize(x->right);
}


array< T* , 2 > split( T* x , int k )
{
	if( x == nullptr )
		return { nullptr , nullptr };

	int leftSize = getSize(x->left); 

	if( k < leftSize )
	{
		auto q = split( x->left , k );
		
		x->left = q[1] ;
		pull(x);
		return { q[0] , x };
	}
	else
	{
		k -= leftSize ; // who will include me 
		k--;
		auto q = split( x->right , k );
		x->right = q[0] ;
		pull(x);
		return { x , q[1] };
	}
}

T* join( T* L , T* R )
{
	if( L == nullptr )
		return R ;
	if( R == nullptr )
		return L ;

	if( L->prior < R->prior )
	{
		L->right = join( L->right , R );
		pull(L);
		return L ;
	}
	else
	{
		R->left = join( L , R->left );
		pull(R);
		return R ;
	}
}


vector<T*> breakSplit( T* x , vector<int>A )
{
	// ( ] // close open type -> [ 0 , A[0]-1 ] , [A[0] , A[1]-1] .... 

	if( A.size() == 0 || x == nullptr )
		return { x } ;
	vector< T* > res ;

	auto ls = split( x , A[0] );
	res.push_back(ls[0]);

	for( int i = 1 ; i < (int)A.size() ; i++ )
	{
		ls = split( ls[1] , A[i]-A[i-1] );
		res.push_back(ls[0]);
	}
	res.push_back(ls[1]);
	return res ;
}

T* mergeJoin( vector<T*> A )
{

	if( A.size() == 0 )
		return nullptr ;

	T* res = A[0];
	for( int i = 1 ; i < (int)A.size() ; i++ )
		res = join( res , A[i] );
	return res ;
}

void dfs( T* root )
{
	if( root == nullptr )
		return ;
	dfs(root->left);
	cout<<root->x;
	dfs(root->right);
}

int main()
{
	// split k ->  [ 0 , k ] [ k+1 , N-1] 
	// breakSpilt( {a , b} ) -> [ 0 , a ] , [a+1 , b ] , [b+1 , N-1 ] 
	return 0 ;
}
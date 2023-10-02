#include <bits/stdc++.h>
using namespace std ;

// Transition matrix 
// https://media.com/
// Y-Tree
int MAX = INT_MAX ;
#define ar array 

class T
{
public:
  T* left ;
  T* right ;
  int size ;
  int key ;
  int prior ;
  T(int key){
  	this->key = key ;
  	this->prior = rand()%INT_MAX ;
  	this->size = 1 ;
  	this->left = nullptr ;
  	this->right = nullptr ;
  }
};

int size( T* x){
	if(x==nullptr)
		return 0;
	return x->size;
}

int prior( T* x )
{
	if( x == nullptr )
		return INT_MAX ;

	return x->prior ;
}

void upd( T* x ){
	if( x== nullptr )
		return ;
	x->size = 1 + size(x->left) + size(x->right);
}

ar< T* , 2 > split( T* p , int k )
{
	if(!p)
		return { nullptr , nullptr };
	if(size(p->left) < k )
	{
		ar< T* , 2 > q = split( p->right , k-size(p->left)-1 );
		p->right = q[0];
		upd(p);
		return { p , q[1] };
	} 

	else
	{
		ar< T* , 2 > q = split( p->left , k );
		p->left = q[1] ;
		upd(p);
		return { q[0] , p };
	}
}

T* merge( T *L , T* R )
{
	if(!L)
		return R; 
	if(!R)
		return L;

	if( prior(L) < prior(R) )
	{
		L->right = merge( L->right , R );
		upd(L);
		return L ;
	}
	else
	{
		R->left = merge( L , R->left );
		upd(R);
		return R ;
	}
}

void go( T* root )
{
	if( root == nullptr )
		return ;
	go(root->left);
	cout<<root->key<<" ";
	go(root->right);
}

vector< T* > breakSplit( T* root ,  vector< int > A )
{
	// [ ) -> closed open type  
	// [ 0 , A[0]-1 ] + [ A[0] , A[1]-1 ] + ..... 
	// 0 based 

	int N = A.size();
	vector< T* > res ;
	if( A.size() == 0 )
		return {} ;
		
	auto ls = split( root , A[0] ); // [ 0 , a-1 ]

	res.push_back(ls[0]);



	for( int i = 1 ; i < N ; i++ )
	{
		ls = split( ls[1] , A[i]-A[i-1] ); // [ a , b-1 ]
		res.push_back(ls[0]);
	}

	res.push_back(ls[1]);

	return res ;
}

T* join( vector< T* > A )
{

	if( A.size() == 0 )
		return 0;
	if( A.size() == 1 )
		return A[0] ; 

	int N = A.size();

	T* res = A[0] ; 

	for( int i = 1 ; i < N ; i++ )
	{
		res = merge( res , A[i] );
	}

	return res; 
}

int main()
{

   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);



#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif


   int N ;
   cin>>N ;
   T* root = nullptr ;

   if( N == 1 )
   {
   	cout<<1<<endl;
   	return 0 ;
   }

   for( int i = 1 ; i <= N ; i++ )
   {
   	  T* x = new T(i);
   	  root = merge( root , x );
   }

   for( int i = 0 ; i < N ; i++ )
   {
   	 int a , b ;
   	 cin>>a>>b ;

   	 a--;
   	 b--;

	if( a >= b )
	continue ;		

   	 int L = min( b-a , N-b );
   	 vector< int > points = { a , a+L , b , b+L };
   	 sort( points.begin() , points.end() );
   	 vector< T* > treaps = breakSplit( root , points );
   	 swap( treaps[1] , treaps[3] );
   	 root = join( treaps );
   }

   go( root ) ;

}


 
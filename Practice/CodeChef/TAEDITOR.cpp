#include <bits/stdc++.h>
using namespace std;

mt19937 mt ;
#define int long long
#define all(x) begin(x) , end(x) 
const int mod = pow(10,9)+7 ;
const int MAX = pow(10,5)+1 ;
const int dx[8] = { 1 , -1 , 0 , 0 , 1 , 1 , -1 , -1 } ;
const int dy[8] = { 0 , 0 , 1 , -1 , 1 , -1 , 1 , -1 } ;
int mod_pow( int a , int b ){if( a == 0 || a == 1 ) return a; if( b == 0 )return 1 ; int ha = mod_pow( a , b/2 ); ha *= ha; ha %= mod ; if( b&1 ) ha *= a ; return ha%mod ;}
int inverse( int a ){return mod_pow(a,mod-2);}
vector<int> fact( int N = MAX ){vector<int>f(N,1);for( int i = 2 ; i < N ; i++ )f[i] = (i*f[i-1])%mod;return f ;}


/********** GO DOWN ***********/

/* 
   If the genius trains just as hard.... 
   what chance do I have to beat him? 
*/


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

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	auto solve = [&]()->void
	{
        T* head = nullptr ;

        int N ;
        cin>>N ;
        for( int i = 0 ; i < N ; i++ )
        {
        	char q ;
        	cin>>q ;
        	if( q == '+')
        	{
        		int k ;
        		string S ;
        		cin>>k>>S ;

        		T* temp = nullptr ;

        		for( auto x : S )
        		{
        			T* nt = new T(x);
        			temp = join( temp , nt );
        		}

        		
        		if( k == 0 )
        		{
        			head = join( temp , head );
        		}
        		else
        		{
        			auto A = split( head , k-1 );
        			head = mergeJoin({ A[0] , temp , A[1] });
        		}
        	}
        	else
        	{
        		int a , len ;
        		cin>>a>>len ;
        		a--;
        		int b = a+len ;
        		

        		auto A = breakSplit( head , { a-1 , b } );

        		dfs(A[1]);
        		cout<<endl;
        		head = mergeJoin({ A[0] , A[1] , A[2] });
        	}

        }

	};
	
	
	
	
	
	
	
	
    int test = 1 ;
	// cin>>test;
	while(test--)
	solve();
	
	return 0;
}
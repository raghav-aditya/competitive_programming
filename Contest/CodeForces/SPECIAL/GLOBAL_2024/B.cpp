/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

#define int long long
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define all(x) begin(x) , end(x) 
#define on(i) (1LL << (i))
#define mask(i) (on(i)-1LL)
#define vi vector<int>
#define vvi vector<vi>
const int mod = pow(10,9)+7 ;
const int MAX = pow(10,5)+1 ;
const int dx[8] = { 1 , -1 , 0 , 0 , 1 , 1 , -1 , -1 } ;
const int dy[8] = { 0 , 0 , 1 , -1 , 1 , -1 , 1 , -1 } ;
int mod_pow( int a , int b , int md = mod )
{
    if( a == 0 || a == 1 ) return a ;
    if( b == 0 )return 1 ;
    int ha = mod_pow( a , b/2 ); ha *= ha; ha %= md ; if( b&1 ) ha *= a ;
    return ha%md ;
}
int inverse( int a )
{
    return mod_pow(a,mod-2);
}
vector<int>factorial_ ; 
vector<int> factorial( int N = MAX )
{
    vector<int>f(N,1);
    for( int i = 2 ; i < N ; i++ )f[i] = (i*f[i-1])%mod;
    return f ;
}
void init_factorial(){ if(factorial_.size()==0)factorial_ = factorial(); }
#define oo (int)pow(2L,60)
#define arr array<int,3> 
#define ar array<int,2>

int nCr( int N , int R )
{
    if(factorial_.size()==0) factorial_ = factorial();
    int res = factorial_[N]; res *= inverse( factorial_[R] );  
    res = (res%mod+mod)%mod; res *= inverse( factorial_[N-R] ); 
    res = (res%mod+mod)%mod; return res ;
}


/********** GO DOWN ***********/

/* 
   If the genius trains just as hard.... 
   what chance do I have to beat him? 
*/


// class seg_tree
// {
// 	vector<int>T ;
// 	int N ;

// public:
// 	seg_tree( vector<int>&A )
// 	{
// 		this->N = A.size();
// 		T.resize(2*N,0);

// 		for( int i = 0 ; i < N ; i++ )
// 			T[i+N] = A[i];

// 		for( int i = N-1 ; i > 0 ;  i-- )
// 			T[i] = max( T[2*i] , T[2*i+1] );
// 	}

// 	int get( int a , int b )
// 	{
// 		int res = 0 ;
// 		for( a += N , b += N+1 ; a < b ; a >>= 1 , b >>= 1 )
// 		{
// 			if(a&1) res = max( res , T[a++] );
// 			if(b&1) res = max( res , T[--b] );
// 		}
// 		return res;
// 	}
// };

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void{
        int N , k ;
        cin>>N>>k ;
        k--;
        vector<int>A(N);
        int mx = 0 ;

	
        for( auto &x : A )cin>>x ;

        auto B = A ;

    	for( int i = 0 ; i < N-1 ; i++ )
    	{
    		int w = max( B[i] , B[i+1] );
    		if( w == B[k] )mx++;
    		B[i+1] = w ;
    	}

    	for( int i = 0 ; i < k ; i++ )
    	{
    		if( A[i] > A[k] )
    		{
    			swap( A[i] , A[k] );
    			k = i ;
    			break;
    		}
    	}

    	int res = 0 ;
    	int v = A[k];

    	for( int i = 0 ; i < N-1 ; i++ )
    	{
    		int w = max( A[i] , A[i+1] );
    		if( w == v )res++;
    		A[i+1] = w ;
    	}

    	cout<<max( mx , res)<<endl;

    };
    

int test = 1 ;
cin>>test;
while(test--)
solve();
return 0;
}   
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

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void{
        int N , c , d ;
        cin>>N>>c>>d ;
        vector<vector<int>>A(N,vector<int>(N,0));

        for( auto &x : A )
        	for( auto &i : x )cin>>i ;

        int mn = INT_MAX ;

    	multiset<int>a,b;


    	for( int i = 0 ; i < N ; i++ )
    	for( int j = 0 ; j < N ; j++ )
    		mn = min( mn , A[i][j] );

    	auto B = A ;

    	B[0][0] = mn ;

    	for( int i = 1 ; i < N ; i++ )
    		B[i][0] = B[i-1][0] + c ;
    	for( int j = 1 ; j < N ; j++ )
    		B[0][j] = B[0][j-1] + d ;

    	for( int i = 1 ; i < N ; i++ )
    	for( int j = 1 ; j < N ; j++ )
    	{

    		if( B[i-1][j] + c != B[i][j-1] + d )
    		{
    			cout<<"NO"<<endl;
    			return ;
    		}

    		B[i][j] = B[i-1][j] + c ;
    	}

    	for( int i = 0 ; i < N ; i++ )
    	for( int j = 0 ; j < N ; j++ )
    	{
    		a.insert(A[i][j]);
    		b.insert(B[i][j]);
    	}

    	if( a == b )
    	{
    		cout<<"YES"<<endl;
    	}
    	else
    	{
    		cout<<"NO"<<endl;
    	}

    };
    

int test = 1 ;
cin>>test;
while(test--)
solve();
return 0;
}   
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

void dfs( vector<string>&A , int i , int j , vector<vector<int>>&vis )
{
	int M = A.size();
	int N = A[0].size();

	if( i < 0 || i >= M || j < 0 || j >= N || A[i][j] != '#' || vis[i][j] == 1 )
		return ;

	vis[i][j] = 1 ;

	for( int p = 0 ; p < 4 ; p++ )
	{
		int a = i + dx[p];
		int b = j + dy[p];

		dfs( A , a , b , vis );
	}
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void{
        
        int M , N , k ;
        cin>>M>>N>>k ;

        vector< string >A(M);
        for( auto &x : A )cin>>x ;

        vector<vector<int>>vis(M,vector<int>(N,0));
    	dfs( A , 0 , 0 , vis );

    	// for( auto x : vis )
    	// {
    	// 	for( auto i : x )
    	// 		cout<<i<<" ";
    	// 	cout<<endl;

    	// }

    	vector<arr>t(k);
    	for( auto &x : t )cin>>x[0]>>x[1]>>x[2];



    	auto count = [&]( int a , int b , int r )-> int {

    		int res = 0 ;
    		int range = r*r ;

    		for( int i = 0 ; i < M ; i++ )
    		for( int j = 0 ; j < N ; j++ )
    		{
    			// if( a == i && b == j )continue;

    			int p = abs(a-i)*abs(a-i);
    			int q = abs(b-j)*abs(b-j);

    			if( A[i][j] == '#' && range >= p+q )
    				res++;
    		}
    		return res;
    	};

    	auto task = [&]( arr B )->int 
    	{
    		int a = B[0];
    		int b = B[1];
    		int p = B[2];

    		// a b -> p 

    		int H = 0 ;
    		int D = 0 ;

    		int mn = INT_MAX ;

    		for( int r = 1 ; r < 10 ; r++ )
    		{
    			H = pow(3,r);
    			D = p*count(a,b,r);
    			cout<<H-D<<" ";
    			mn = min( mn , H-D );
    		}
    		cout<<endl;
    		return min( 0LL , mn );
    	};
    	int res = 0 ;
    	for( auto x : t )
    	{
    		res += task(x);
    	}
    	cout<<" -> ";
    	cout<<abs(res)<<endl;
    	cout<<endl;
    };
    

int test = 1 ;
cin>>test;
while(test--)
solve();
return 0;
}   
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

bool is_prime( int N )
{
	for( int i = 2 ; i*i <= N ; i++ )
	{
		if(N%i == 0 )
			return 0 ;
	}
	return 1 ;
}
arr two_devisor( int N )
{
	if(is_prime(N))
		return {0,-1,-1};
	int cnt = 0 ;
	int p = -1 ;
	for( int i = 2 ; i*i <= N ; i++ )
	{
		if(N%i==0){
			cnt++;
			p = i ;
		}
		if( cnt > 2 )
			return {0,-1,-1} ;
	}
	return { 1 , p , N/p };
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void{
        int N ;
        cin>>N ;

        vector<int>A(N);
        for( auto &x : A )cin>>x ;
		
		int cnt = 0 ;
		unordered_map< int , int > mp1, mp2 ;
		for( auto x : A )
		{
			if( is_prime(x)){
				mp1[x]++;
				cnt++;
			}
			
			if( two_devisor(x)[0])
				mp2[x]++;
		}

		int res = (cnt*(cnt-1))/2;

		for( auto x : mp2 )
		{
			int a = x.first ;
			int b = x.second ;

			cout<<a<<" ";

			auto beg = two_devisor(a);
			int p = beg[1];
			int q = beg[2];

			res += b * mp1[q] ;
			res += b * mp1[p] ;
			if( p == q )
				res -= b * mp1[p];
		}
		cout<<endl;
		cout<<res<<endl;
    };
    

int test = 1 ;
cin>>test;
while(test--)
solve();
return 0;
}   
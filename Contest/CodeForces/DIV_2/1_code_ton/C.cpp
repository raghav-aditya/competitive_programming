/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
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

int go( vector<int>&A )
{
	int N = A.size();
	vector<int>B ;
	for( int i = 0 ; i < N ; i++ )
	{
		int j = (i+1)%N ;
		int v = abs(A[i]-A[j]);
		v %= 2 ;
		B.push_back(v);
	}

	int mn = 1 ;
	if( N == 4 )
		mn = 2 ;

	return 1 ;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void
    {
    	int N , x , y ;
    	cin>>N>>x>>y ;
    	vector<int>A(x);
    	for( auto &x_ : A )cin>>x_ ;
    	sort( A.begin() , A.end() );
    	if( A.back() != N )
    		A.push_back(N);
    	// cout<<go(A)<<endl;
    	go(A);
    };
    

    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
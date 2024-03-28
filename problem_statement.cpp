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

int get( int C , int P , int N , int k )
{
    if( N == k )
        return N*P ;
    int times = N/k - (N%k==0) ;

    int del = P*k - C ;
    int res = 0 ;
    if( del > 0 )
    {
        res = times*del ;
    }
    if(N%k==0)
        res += k*P ;
    return res;
}

int f( int C , int P , vector<int> A ){

    int N = A.size();
    sort( A.begin() , A.end() );


    int res = 0 ;

    for( int a = 1 ; a <= 10010; a++ )
    {
        int lc = 0 ;

        for( int j = 0 ; j < N ; j++ )
        {
            if( A[j] >= a )
            {
                int sol = get( C , P , A[j] , a );
                lc += sol ;
            }
        }
        res = max( res , lc );
    }
    return res ;
}   

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> A = { 26 , 59 , 103 };

    cout<<f( 1 , 10 , A )<<endl;
    
    return 0;
}
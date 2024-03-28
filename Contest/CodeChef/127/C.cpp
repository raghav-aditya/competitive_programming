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


int task( int N )
{
    int res = 0 ;

    for( int i = 2 ; i*i <= N ; i++ )
    {
        int a = 1 ;
        while( N%i == 0 )
        {
            a *= i ;
            N /= i ;
        }

        res = max( res , a );
    }

    res = max( res , N );

    return res ;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    int k = 3*pow(10,5)+10;
    vector<int>A(k);
    for( int i = 1 ; i < k ; i++ ){
        A[i] = task( i );
    }

    vector<int>P(k+1,0);
    for( int i = 0 ; i < k ; i++ )
        P[i+1] = P[i] + A[i];

    auto get = [&]( int a , int b )-> int {
        return P[b+1] - P[a] ;
    };

    auto solve = [&]()->void
    {   
        int L , R ;

        cin>>L>>R ;

        if( L == 1 )
        {
            cout<<get( 1 , R )<<endl;
        }   
        else
        {
            cout<<"not done yet"<<endl;
        }
            
    };
    

    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
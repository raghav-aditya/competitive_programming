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


    // vector< vector< int > >A(3, vector<int>(3,0));

    // for( auto &x : A )
    // for( auto &i : x )
    //     cin>>i ;

    // int M = A.size();
    // int N = A[0].size();

    // auto dp_max = A ;
    // auto dp_min = A ;

    // for( int i = 0 ; i < M ; i++ )
    // for( int j = 0 ; j < N ; j++ )
    // {
    //     dp_max[i][j] = A[i][j];
    //     dp_min[i][j] = A[i][j];
    // }

    // for( int i = 1 ; i < M ; i++ )
    // {
    //     dp_max[i][0] = max( dp_max[i][0] , dp_max[i-1][0] ) ;
    //     dp_min[i][0] = min( dp_min[i][0] , dp_min[i-1][0] );
    // }

    // for( int j = 1 ; j < N ; j++ )
    // {
    //     dp_max[0][j] = max( dp_max[0][j] , dp_max[0][j-1] );
    //     dp_min[0][j] = min( dp_max[0][j] , dp_min[0][j-1] );
    // }



    // for( int i = 1 ; i < M ; i++ )
    // for( int j = 1 ; j < N ; j++ )
    // {
    //     int mx = dp_max[i][j];
    //     int mn = dp_min[i][j];

    //     mx = max(
    //             mx , 
    //             min( dp_max[i][j-1] , dp_max[i-1][j] )
    //         );

    //     mn = min(
    //             mn , 
    //             max( dp_min[i][j-1] , dp_min[i-1][j] )
    //         );

    //     dp_max[i][j] = mx ;
    //     dp_min[i][j] = mn ;
    // }


    // for( int i = 0 ; i < M ; i++ )
    // {
    //     for( int j = 0 ; j < N ; j++ )
    //         cout<<dp_max[i][j]<<" ";
    //     cout<<endl;
    // }

    // cout<<endl;
    // cout<<endl;
    // cout<<endl;

    // for( int i = 0 ; i < M ; i++ )
    // {
    //     for( int j = 0 ; j < N ; j++ )
    //         cout<<dp_min[i][j]<<" ";
    //     cout<<endl;
    // }

    // cout<<dp_max[M-1][N-1] - dp_min[M-1][N-1]<<endl;


    // 4D dp for solving all paths version
    // sorting and two pionter for jumping on columns only version

    return 0;
}
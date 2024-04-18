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

// ar is basically : array< int, 2 >
// arr is basically : array< int , 3 >


vector<ar> merge( vector<ar>&t , int f = 1 )
{
    vector<ar> res ;

    int a = t[0][0];
    int b = t[0][1];

    for( auto x : t )
    {
        int c = x[0];
        int d = x[1];

        if( c <= b+f )
        {
            a = min( a , c );
            b = max( b , d );
        }
        else
        {
            res.push_back({a,b});
            a = c ;
            b = d ;
        }
        // [ a , b ] || [ c , d ]
    }
    res.push_back({a,b});
    return res;
}

int32_t main() {
    
vector< ar > A = { {1,8},{2,5},{6,11},{8,9},{14,17},{17,20},{19,23},{20,28},{24,27},{26,28},{30,34},{33,36},{34,40},{38,41},{43,48},{45,50} };
vector< int > B = { 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1 };
vector< ar > I,U ;

map< int , int > mp ;

int F = 1e6; 
// this factor distinguishes wether given range is important or not during sweep, and also and we can distinguised between 
// zero range and unimportant interval range 

for( int i = 0 ; i < A.size() ; i++ )
{
    int a = A[i][0];
    int b = A[i][1];

    if(B[i])
    {
        I.push_back(A[i]); // important intervals dont changes so they are part of ans already 
        mp[a] += F ;
        mp[b+1] -= F ;
    }
    else
    {
        mp[a]++;
        mp[b+1]--;
    }
}

int st = -1 ;
int s = 0 ;

for( auto x: mp )
{
    int a = x.first ;
    int b = x.second ;

    if( s > 0 && s < F )
    U.push_back({ st , a-1 });
    s += b ;
    st = a ;
}

I = merge(I,0); // important intervals are in exact merge  [ 1 , 1 ] [ 1 , 3 ] = [ 1 , 3 ]
U = merge(U); // unimportant intervals can merge in [ 0 1 ] [ 2 , 3 ] = [ 0 , 3 ]

vector< ar > res ;
for( auto x : I )
    res.push_back(x);

for( auto x : U )
    res.push_back(x);

sort(all(res));

for( auto x : res )
    cout<<x[0]<<" "<<x[1]<<endl;


return 0;
}   



/*

intervals = {1,8},{2,5},{6,11},{8,9},{14,17},{17,20},{19,23},{20,28},{24,27},{26,28},{30,34},{33,36},{34,40},{38,41},{43,48},{45,50}
important = 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1
Ans: {1,1},{2,5},{6,11},{14,16},{17,28},{30,34},{35,37},{38,41},{43,44},{45,50}

*/
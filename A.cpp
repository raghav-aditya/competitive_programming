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


class Hash {

    string A ;
    vector<int> F ; // forward prefix sum of hash
    vector<int> B ; // backward prefix sum 
    vector<int> t ; // power of base 
    vector<int> ti ;
    int base ;
    int N ;

public:

    Hash( const int base_ , const string &A_ ){
        this->base = base_ ;
        this->A = A_ ;
        this->N = A.size();

        F.resize(N+2,0);
        B.resize(N+2,0);
        t.resize(N+2,1);
        ti.resize(N+2,0);

        ti[0] = inverse(1);
        int inv_base = inverse(base);

        for( int i = 1 ; i <= N ; i++ )
            ti[i] = ((ti[i-1] * inv_base)%mod + mod) %mod ;

        for( int i = 1 ; i <= N ; i++ )
            t[i] = ( (t[i-1]*base)%mod + mod )%mod ;

        for( int i = 0 ; i < N ; i++ )
        {
            int x = A[i];
            int y = A[N-i-1];

            F[i+1] = ((F[i] + (x*t[i+1])%mod)%mod + mod)%mod  ;
            B[i+1] = ((B[i] + (y*t[i+1])%mod)%mod + mod)%mod ;
        }

    }

    int get( int a , int b , bool is_reverse = false )
    {
        if(!is_reverse)
        {
            int res = ((F[b+1] - F[a])%mod +mod)%mod ;
            res = ((res*ti[a])%mod + mod )%mod ;
            return res;
        }
        else
        {
            swap( a, b ); 
            a = N-1-a ;  
            b = N-1-b ;   
            int res = ((B[b+1] - B[a])%mod +mod)%mod ;
            res = ((res*ti[a])%mod + mod )%mod ;
            return res;
        }
    }

    bool is_substring_pallindrom( int i , int j ){
        return get( i , j ) == get( i , j , 1 );
    } 

    bool isPallindrome()
    {
        return get( 0 , N-1 ) == get( 0 , N-1 , 1 );
    }
};

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void{
        
        cout<<"fjdkla;fjdkal;f"<<endl;

    };
    


solve();
return 0;
}   
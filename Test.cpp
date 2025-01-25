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

ar join( ar a , ar b )
{
    if( a[0] > b[0] )
        return a ;
    else if( b[0] > a[0] )
        return b ;

    else if( a[0] == b[0] )
    {
        if( a[1] <= b[1] )
            return a ;
        else
            return b ;
    }

    return a ;
}

class seg_tree
{
public:
    vector<ar>T ;
    int N ;

    seg_tree(vector<int>A)
    {
        N = A.size();
        T.resize(2*N);
        
        for( int i = 0 ; i < N ; i++ )
            T[i+N] = { A[i] , i } ;

        for( int i = N-1 ; i > 0 ; i-- )
            T[i] = join( T[i<<1] , T[i<<1|1]);
    }

    void update( int p , int x )
    {
        
        for( T[p+=N][0] = x ; p >>=1 ;  ){
            T[p] = join(T[p<<1] , T[p<<1|1]) ;
        }
    }

    ar get( int a , int b )
    {
        ar res = { -1 , -1 } ;
        for( a += N , b += N+1 ;  a < b ; a >>= 1 , b >>= 1 )
        {
            if(a&1) res = join( res , T[a++] );
            if(b&1) res = join( res , T[--b] );
        }
        return res ;
    }

};

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->int {
        
        int k = 3 ;
        vector<int>A = 
        
        // { 17 , 12 , 10 , 2 , 7 , 2 , 11 , 20 , 8 }; // test case 2 
        {10,20,10,15,5,30,20}; // test case 1 

        int T = 2 ;

        int sum = accumulate( A.begin() , A.end() , 0LL );
        if( A.size() <= T )
        {
            return sum ;
        }

        int N = A.size();
        seg_tree st(A);

        int curr = 0 ;
        int res = 0 ;

        int l1 = 0 ;
        int r1 = k-1 ;

        int l2 = N-k ; 
        int r2 = N-1 ;

        while( curr++ < T )
        {

            auto a = st.get( l1 , r1 );
            auto b = st.get( l2 , r2 );

            auto c = join( a , b );


            if( a[0] == b[0] || a == b || c == a )
                r1++;
            else
                l2--;

            l2 = max( 0LL , l2 );
            r1 = min( N-1 , r1 );
            

            st.update( c[1] , 0 );

            res += c[0] ;            
        }

        return res ;

    };
    

int test = 1 ;
// cin>>test;
while(test--)
cout<<solve()<<endl;
return 0;
}   
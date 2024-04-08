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


class binary_lifting{
    vector< vector<ar> > g ;
    vector< vector<ar> > t ;
    int N ;
    int k ;
    vector< int > in , out ;
    int timer = -1 ;

    void dfs( int u , int p , int w )
    {
        in[u] = ++timer ;

        t[u][0] = { p , w };

        for( int L = 1 ; L < k ; L++ )
        {
            auto a = t[u][L-1];
            auto b = t[a[0]][L-1];

            t[u][L][0] = (b[0]);
            t[u][L][1] = (max(a[1],b[1]));
        }

        for( auto v : g[u] )
        {
            int child = v[0];
            int weight = v[1];

            if( child == p )continue;

            dfs( child , u , weight );
        }
        out[u] = timer ;
    }

    bool is_ancestor( int a , int b){
        return in[a] <= in[b] && out[b] <= out[a];
    }

    int lca( int a, int b ){

        if( is_ancestor( a , b ) )
            return a ;
        if( is_ancestor( b , a ) )
            return b;

        for( int L = k-1 ; L >= 0 ; L-- ){
            if( is_ancestor( t[b][L][0] , a ) ) continue ;
            b = t[b][L][0];
        }
        return t[b][0][0];
    }

    int task( int l , int a ){
        int res = 0 ;
        if( l == a )
            return res;
        for( int L = k-1 ; L >= 0 ; L-- ){
            if( is_ancestor( t[a][L][0] , l ) ) continue ;
            res = max( res , t[a][L][1]);
            a = t[a][L][0];            
        }
        res = max( res , t[a][0][1] );  
        return res;
    }

public:

    binary_lifting( vector< vector<ar> > &g_ )
    {
        this->g = g_ ;
        this->N = g.size();
        this->k = log2(N)+1;
        vector< vector< ar > >t_( N , vector<ar>(k,{0,0}) ) ;
        this->t = t_ ;
        in.assign(N,0);
        out.assign(N,0);
        timer = -1 ;
        t_.clear();
        dfs( 0 , 0 , 0 );
    }

    int path_query( int a , int b ){
        int l = lca( a , b );
        return max( task( l , a ) , task( l , b ) );
    }
};



int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void{
        
        
    
        int N ;
        cin>>N;
        vector< arr > A(N);

        for( int i = 0 ; i < N-1 ; i++ )
        {
            cin>>A[i][1]>>A[i][2];
            A[i][0] = 1 ;
        }
        
       
    };
    

int test = 1 ;
// cin>>test;
while(test--)
solve();
return 0;
}   
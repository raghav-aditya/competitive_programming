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


class seg_tree{
    vector<int>T ;
    int N ;

public:
    seg_tree(){

    }
    seg_tree( const vector<int>A )
    {
        this->N = A.size();
        T.resize(2*N,0);

        for( int i = 0 ; i < N ; i++ )
        T[i+N] = A[i];

        for( int i = N-1 ; i > 0 ; i-- )
            T[i] = max( T[2*i] , T[2*i+1] );
    }

    int get( int a , int b)
    {
        int res = INT_MIN ;
        for( a += N , b += N+1 ; a < b ; a >>= 1 , b >>= 1 ){
            if(a&1) res = max( res , T[a++] );
            if(b&1) res = max( T[--b] , res );
        }
        return res;
    }

    void update( int p , int x )
    {
        p += N ;
        T[p] = x ;
        for( ; p>>= 1 ; )
            T[p] = max( T[2*p] , T[2*p+1] );
    }
};


vector<int>heavy,head,par,depth,sz;
vector<int>tin,tout;
vector<int>E ;
vector<int>pos ;
int t = 0 ;
seg_tree st ;

void dfs( vector<int>g[] , int u , int p )
{
    sz[u] = 1 ;
    int mx = 0 ;
    for( const auto &v : g[u] )
    {
        if( v == p )continue;
        dfs( g , v , u );

        sz[u] += sz[v];
        depth[v] = depth[u] + 1 ;
        par[v] = u ;

        if( sz[v] > mx )
        {
            mx = sz[v] ;
            heavy[u] = v ;
        }
    }
}

void hld( vector<int>g[] , int u , int p , int h )
{
    tin[u] = ++t ;
    E.push_back(u);
    head[u] = h ;


    if( heavy[u] != -1 )
        hld( g , heavy[u] , u , head[u] );

    for( auto v : g[u] )
    {
        if( v == p || v == heavy[u] )continue ;
        hld( g , v , u , v);
    }
    tout[u] = t ;
}

void print( vector<int>&k )
{
    for( auto x : k )
        cout<<x<<" ";
    cout<<endl;
}


int query( int a , int b ){

    int res = INT_MIN ;
    for( ; head[a] != head[b] ; b = par[head[b]] ){

        if( depth[head[a]] > depth[head[b]] )
            swap(a , b);
        res = max( res , st.get( pos[head[b]] , pos[b] ) );
    }

    if( pos[a] > pos[b] )
        swap( a , b );

    // cout<<pos[a]<<" "<<pos[b]<<endl;

    res = max( res , st.get( pos[a] , pos[b] ));

    cout<<res<<endl;

    return res;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void{
        
        int N , Q ;
        cin>>N>>Q ;
                            
        vector<int>A(N);
        for( auto &x : A )cin>>x ;     

        heavy.resize(N,-1);
        head.resize(N,0);
        par.resize(N,0);
        sz.resize(N,0);
        depth.resize(N,0);
        tin.resize(N,0);
        tout.resize(N,0);
        pos.resize(N,0);
        E.clear();

        vector<int>g[N];
        for( int i = 0 ; i < N-1 ; i++ )
        {
            int a , b ;
            cin>>a>>b ;
            a--;b--;
            // cout<<a<<" "<<b<<endl;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        t = -1 ;
        dfs( g , 0 , -1 );
        hld( g , 0 , -1 , 0 );

        for( int i = 0 ; i < N ; i++ )
            pos[E[i]] = i ;

        // print(E);
        for( auto &x : E )
            x = A[x] ;
        // print(E);

        seg_tree st_(E);
        st = st_ ;

        for( int i = 0 ; i < Q ; i++ )
        {
            int type ;
            cin>>type;
            if( type == 1 ){
                int p , x ;
                cin>>p>>x ;
                // cout<<p<<" "<<x<<endl;
                p--;
                int k = pos[p];
                st.update(k,x);
            }
            else
            {
                int a , b ;
                cin>>a>>b ;
                a--;b--;
                query( a , b );

                // return ;
            }
        }

    };
    

int test = 1 ;
while(test--)
solve();
return 0;
}   

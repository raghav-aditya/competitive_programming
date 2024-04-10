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

class T 
{
public:
    T* left = nullptr ;
    T* right = nullptr ;
    int st , en ;
    int lazy = 0 ;
    int data = 0 ;

    T( int st_ , int en_ ){
        this->st = st_ ;
        this->en = en_ ;
    }

    void insert( int x ){
        data |= on(x);
    }

};

class seg_tree
{
    T* home_root = nullptr ;
    vector<int>A ;
    int N ;

    void pull( T* node )
    {
        if( node == nullptr )
            return ;

        int res = 0 ;

        if( node->left )
        {
            res |= node->left->data ;
        }

        if( node->right )
        {
            res |= node->right->data ;
        }

        node->data = res ;
    }


    void push( T* node )
    {
        if( !node || node->lazy == 0 )
            return;

        int L = node->lazy ;
        node->lazy = 0 ;
        node->data = on(L) ;

        if( node->left )
            node->left->lazy = L ;
        if( node->right )
            node->right->lazy = L ;
    }

    T* build( int st , int en )
    {
        if( st >  en )
            return nullptr ;

        int m = (st+en)>>1 ;

        T* node = new T(st,en);

        if( st == en )
        {
            node->insert(A[st]);
        }
        else
        {
            node->left = build( st , m );
            node->right = build( m+1, en );
            pull( node );
        }   
        return node ;     
    }

    void update( T* node , int l , int r , int x )
    {
        push(node);
        if( node == nullptr )
            return ;
        if( r < (node->st) || (node->en) < l )
            return ;

        if( l <= (node->st) && (node->en) <= r )
        {
            node->lazy = x ;
            push(node);
        }
        else
        {
            update( node->left , l , r , x );
            update( node->right , l , r , x );
            pull(node);
        }
    }

    int get( T* node , int l , int r )
    {
        push(node);
        int res = 0;
        if( node == nullptr )
            return res ;
        if( r < (node->st) || (node->en) < l )
            return res ;

        if( l <= (node->st) && (node->en) <= r ){
            res = node->data ;
            return res;
        }
        else{
            auto L = get( node->left , l , r );
            auto R = get( node->right , l , r );
            return (L|R) ;
        }
    }

public:
    seg_tree( vector<int>&A_ )
    {
        this->A = A_ ;
        N = A.size();
        home_root = build( 0 , N-1 );
    }

    void update( int l , int r , int x )
    {
        update( home_root , l , r , x );
    }

    int get( int l , int r )
    {
        int k  = get( home_root , l , r );

        int res = 0;
        for( int i = 0 ; i <= 60 ; i++ ){
            if(on(i)&k){
                res++;   
            }
        }
        return res;
    }

    void print()
    {
        for( int i = 0 ; i < N ; i++ )
        {
            get(i,i);
        }

        cout<<endl;
        cout<<endl;
        cout<<endl;
    }
};


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void{
                
        vector<int>A = { 1 , 1 , 1 };
        seg_tree st(A);
        int N = A.size();
       
        st.update(0,N-1,10);
        st.get(0,N-1);
        // st.print();
        st.update(N-1,N-1,5);
        // st.print();
        st.get(0,N-1);
       
    };
    

int test = 1 ;
// cin>>test;
while(test--)
solve();
return 0;
}   
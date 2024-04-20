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
    string data ;
    bool is_file = 0 ;
    bool is_seen = 0 ;
    int count = 0 ;

    unordered_map< string , T* > child ;

    T( string data_ )
    {
        this->data = data_ ;
        for( auto x : data_ )
        {
            if( x == '.' )
                is_file = 1 ;
        }
    }    
};


class TRIE
{
    T* root = new T("#");

    vector< string > split( string A )
    {
        for( auto &x : A )
        {
            if( x == '/' )
                x = ' ';
        }

        stringstream ss(A);
        string x ;

        vector< string > res ;
        while( ss>>x )
            res.push_back(x);

        return res;
    }

    void print( vector<string>&A )
    {
        for( auto x : A )
        {
            if( x == "#" )
                continue;

            cout<<"/"<<x;
        }
        cout<<endl;
    }

    void dfs( T* node , vector<string>&res )
    {
        res.push_back(node->data);

        if( node->count == 0 ){
            print(res);
        }
        else
        {
            for( auto beg : node->child )
            {
                T* cp = beg.second ;
                dfs( cp , res );                
            }
        }            
        res.pop_back();
    }

public:

    TRIE(){
        root->is_seen = true ;
        root->count += 10000 ;
    }

    void insert( string A )
    {
        T* node = root ;
        auto B = split(A);

        for( auto x : B )
        {
            if( node->child[x] == nullptr )
            {
                T* temp = new T(x);
                node->child[x] = temp ;
            }
            node = node->child[x];
            node->count++;
        }
    }

    void visit( string A )
    {
        T* node = root ;
        auto B = split(A);

        node->is_seen = true ;
        for( auto x : B )
        {
            node = node->child[x] ;
            node->is_seen = true ;
            node->count--;
        }
    }

    void task()
    {
        vector<string>res;
        T* node = root ;
        dfs( node , res );
    }
};

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

vector< string > all_files = {
    "a/b/c/d.txt",
    "a/b/c/e.txt",
    "a/b/b.txt",
    "a/b/e.txt",
    "b/c/d.txt"
};
    
vector< string > seen_files = {

    "a/b/c/d.txt",
    "a/b/c/e.txt",
    "a/b/b.txt",
    "b/c/d.txt"

};


TRIE trie ;

for( auto x : all_files )
    trie.insert(x);

for( auto x : seen_files )
    trie.visit(x);

trie.task();

return 0;
}   
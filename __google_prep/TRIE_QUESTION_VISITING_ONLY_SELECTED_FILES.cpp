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


struct T 
{
    string data ;
    unordered_map< string , T* > child ;
    bool isFile = false ;
    bool seen = false ;
    int seen_count = 0 ; // all seen files in my subfolder
    int file_count = 0 ; // all files in my subfolder

    T( string data_ ){
        this->data = data_ ;

        for( auto x : data_ )
            if( x == '.' )
                isFile = true ;
    }
};


class TRIE
{
    T* root = new T("#");

    void print( vector<string>A ){
        for( auto x : A ){
            if( x != "#" )
            cout<<"/"<<x;
        }
        cout<<endl;
    }

    vector< string > split( string A )
    {
        for( auto &x : A )
        {
            if( x == '/' )x = ' ';
        }

        string x ;
        stringstream ss(A);

        vector<string>res ;

        while( ss>>x )
            res.push_back(x);

        return res ;
    }

    void dfs( T* node , vector<string>&res )
    {
       res.push_back(node->data);

       string lst_file = "";
       int cnt = 0 ;

       for( auto beg : node->child )
       {
            string val = beg.first ;
            T* ch = beg.second ;

            if( ch->seen )
            {
                if( ch->isFile ){
                    lst_file = val ;
                    cnt++;
                }
                else
                    dfs( ch , res );
            }
       }

       if( cnt == 1 )
       {
            res.push_back(lst_file);
            print(res);
            res.pop_back();
       }
       else if( cnt > 1 )
       {
            print(res);
       }

       res.pop_back();
    }


public:


    TRIE(){};

    void insert( string A){

        auto B = split(A);

        T* node = root ;

        for( int i = 0 ; i < B.size() ; i++ )
        {
            string x = B[i];
            if( node->child[x] == nullptr )
            {
                T * temp = new T(x);
                node->child[x] = temp ;
                node->file_count += temp->isFile ;
            }
            node = node->child[x] ;
        }
    }


    void visit ( string A ){

        auto B = split(A) ;

        T* node = root ;
        node->seen = true ;

        for( int i = 0 ; i < B.size() ; i++ )
        {
            string x = B[i];
            
            if( node->child[x]->isFile )
                node->seen_count++;

            node = node->child[x];
            node->seen = true ;

        }
    }


    void task(){

       T* node = root ;
       vector<string>res;
       dfs( node , res );
    }
};

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        
    vector<string>all_directory = {
"/a/b/x.txt",
"/a/b/p.txt",
"/a/c",
"/a/d/y.txt",
"/a/d/z.txt"
    };
    

    vector< string > visited_directory = {
"/a/d/y.txt",
"/a/d/z.txt",
"/a/b/p.txt"
    };


    TRIE trie;

    for( auto x : all_directory )
        trie.insert(x);

    for( auto x : visited_directory )
        trie.visit(x);

    trie.task();

return 0;
}   



/*

allFiles = [
"/a/b/x.txt",
"/a/b/p.txt",
"/a/c",
"/a/d/y.txt",
"/a/d/z.txt"
]
subsetFiles = [
"/a/d/y.txt",
"/a/d/z.txt",
"/a/b/p.txt"
]
output=[
"/a/d",
"/a/b/p.txt"
]


*/
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

class STREAM_PROCESSOR
{
    int D ;
    multiset< int > st ;

    void process( multiset<int>::iterator it )
    {
        vector<int>A ;
        A.push_back(*it);

        auto t = it ;
        int k = 2 ;

        while( k-- > 0 && t != st.begin() )
        {
            t = prev(t);
            A.push_back(*t);
        }

        t = it ;
        k = 2 ;

        while( k-- > 0 && t != prev(st.end()) )
        {
            t = next(t);
            A.push_back(*t);
        }

        sort(all(A)); // O(1) only as there can be atmast 5 peoples are there
        int L = 3 ;
        int N = A.size();

        for( int i = 0 ; i+L-1 < N ; i++ )
        {
            int j = i+L-1;

            if( abs(A[j]-A[i]) <= D )
            {
                cout<<A[i]<<" "<<A[i+1]<<" "<<A[j]<<endl;

                st.erase( st.find(A[i]) );
                st.erase( st.find(A[i+1]));
                st.erase( st.find(A[i+2]));
                return ;
            } 
        }
        return;        
    }

public:

    STREAM_PROCESSOR( int D_ )
    {
        this->D = D_;
    }

    void insert( int x )
    {
        auto it = st.insert(x);
        if( st.size() < 3 )
            return ;
        process(it);
    }
};

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    STREAM_PROCESSOR tool(5);

    vector<int>A = { 1 , 10 , 7 , -2 , 8 };

    for( auto x : A )
    {
        tool.insert(x);
    }
  
return 0;
}   
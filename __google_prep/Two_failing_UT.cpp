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

int test(vector<int>A) // this is api call 
{
    int t1 = 6 ; // test case one 
    int t2 = 9 ; // test case two 

    int f1 = 0;
    int f2 = 0;
    for( auto x : A )
    {
        f1 |= (x==t1);
        f2 |= (x==t2);
    }
    
    return f1&f2 ;
}

ar res = { -1 , -1 };

void find( vector<int>&A , int st , int en )
{
    int m = (st+en)/2 ;

    if( en - st + 1 < 2 )
        return ;

    if( en - st + 1 == 2 )
    {
        res = { A[st] , A[en] };
        return ;
    }

    vector<int>f( A.begin()+st , A.begin()+m+1 );
    vector<int>s( A.begin()+m+1, A.begin()+en) ;

    if( test(f) )
    {
        find( A , st , m );
    }
    else if( test(s) )
    {
        find( A , m+1 , en );
    }
    else
    {
        for( int del = 0 ; del <= 1 ; del++ ) // we will try to swap one UT from second part to first part 
        for( int j = m+1 ; j <= en ; j++ ) // we only need to do it for only two places in first part 
        {
            int id = st + del ;

            swap( A[id] , A[j] );

            vector<int> temp( A.begin()+st , A.begin()+m+1 );
            if( test(temp) )
            {   
                find(A , st , m );
                return ;
            }

            swap( A[id] , A[j] );
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector< int > A(10);
    iota( all(A) , 1 );
    int N = A.size();
    find(A,0,N-1);

    cout<<res[0]<<" "<<res[1]<<endl;


    // i can binary search right UT and after that just with with other N UT to find the otherone

return 0;
}   
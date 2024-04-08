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


class DSU
{
    vector< int > par ;
    vector< int > size ;
    int N ;

public:

    DSU( int sz )
    {
        this->N = sz ;
        par.resize(N,0);
        iota( par.begin() , par.end() ,0);
        size.resize(N,1);
    }

    int find( int x )
    {
        if( par[x] == x )
            return x ;
        return par[x] = find( par[x] );
    }

    int get( int x )
    {
        return size[find(x)] ;
    }

    void join( int a , int b )
    {
        if( is_same( a, b) )
            return ;
        
        int L = get(a) ;
        int R = get(b) ;

        if( L > R )
        {
            swap( L , R );
            swap( a , b );
        }

        par[find(a)] = find(b);
        size[find(a)] = L + R ;
    }

    bool is_same( int a , int b )
    {
        if( find(find(a)) == find(find(b)) )
        return 1 ;

        return 0 ;
    }
};


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void{
        
    	int N , k ;
    	cin>>N>>k ;

    	if( N == k )
    	{
    		cout<<"YES"<<endl;
    		cout<<1<<endl;
    		cout<<1<<endl;
    		return ;
    	}

    	if( k == 1 )
    	{
    		cout<<"YES"<<endl;
    		cout<<1<<endl;
    		cout<<N<<endl;
    		return ;
    	}

		int a = (N-1)>>1 ;
		k--;


		if( a < k )
		{
			cout<<"NO"<<endl;
			return ;
		}
		else{
			cout<<"YES"<<endl;
			int diff = k ;
			cout<<2<<endl;
			cout<<N-diff<<" "<<1<<endl;
			return ;
		}
    };
    

int test = 1 ;
cin>>test;
while(test--)
solve();
return 0;
}   
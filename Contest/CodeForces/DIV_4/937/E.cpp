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

class Hash
{
	 string A ;
	 // int mod = pow(10,9)+7 ;
	 vector< int > P ;
	 vector< int > t ;
	 int N ;
	 int base ;

	public:

		Hash(){}
		Hash( int base_ , string A_ )
		{
			A = A_ ;
			N = A.size();
			base = base_ ;

			P.resize( N+10 , 0 );
			t.resize( N+10 , 1 );

			for( int i = 1 ; i <= N+3 ; i++ )
			{
				t[i] = ((base*t[i-1])%mod + mod)%mod ;
				t[i] %= mod ;
			}

			P[0] = 0 ;

			for( int i = 0 ; i < N ; i++ )
			{
				P[i+1] = ((P[i] + (A[i]*t[i+1])%mod)%mod + mod)%mod ;
			}
		}

		int get( int a , int b )
		{
			int res = P[b+1] - P[a];
			res%= mod;
			res = (res+mod)%mod;

			int kk = inverse( t[a] );
			res *= kk ;
			res %= mod ;
			res += mod ;
			res %= mod ;

			return res;
		}
};



int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void
    {

    	int N ;
    	cin>>N ;
    	string A ; 
    	cin>>A ;

    

    	


    	vector< int > pp = 
    	// { 167 };
    	{ 167
    	,173	,179	,181};
    	vector< Hash > tool ;

    	for( auto x : pp )
    	{
    		Hash t1( x , A );
    		tool.push_back(t1);
    	}


    	auto ok = [&]( int m )-> bool{

    			int L = m ;
    			int T = N/L ;


    		for( int k = 0 ; k < pp.size() ; k++ )
    		{

    			 map< int , int > mp ;
    			 for( int i = 0 ; i+L-1 < N ; i += L )
    			 {
    			 	int j = i+L-1;
    			 	mp[ tool[k].get(i,j)]++;
    			 }

    			 if( mp.size() > 2 )
    			 return 0 ;


    			if( mp.size() == 1 )
    				continue;

    			int a = 0 ; 

    			for( auto x : mp )
    			{
    				if( x.second != 1 && x.second != T-1 )
    					return 0 ;

    				if( x.second == 1 )
    				{
    					a = x.first ;
    				}
    			}

    			string orig ;
    			string copy ;

    			for( int i = 0 ; i+L-1 < N ; i+=L )
    			{
    				int j = i+L-1;

    				if( tool[k].get( i , j ) == a )
    				{
    					orig = A.substr(i,L);
    				}
    				else 
    				{
    					copy = A.substr(i,L);
    				}

    				if( orig.size() && copy.size() )
    					break;
    			}


    			int cnt = 0 ;
    			for( int i = 0 ; i < orig.size() ; i++ )
    			cnt += orig[i] != copy[i];

    			if( cnt > 1 )
    				return 0;

    		}

    		return 1;
  			
    	};


    	for( int i = 1 ; i <= N ; i++ )
    	{
    		if((N%i)==0){
    			if(ok(i))
    			{
    				cout<<i<<endl;
    				return ;
    			}

    		}
    	}
    };
    

    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
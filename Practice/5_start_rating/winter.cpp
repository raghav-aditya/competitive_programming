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
int mod_pow( int a , int b )
{
    if( a == 0 || a == 1 ) return a ;
    if( b == 0 )return 1 ;
    int ha = mod_pow( a , b/2 ); ha *= ha; ha %= mod ; if( b&1 ) ha *= a ;
    return ha%mod ;
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

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void
    {
    	int N , M , Q ;
    	cin>>N>>M>>Q ;
    	vector<int>g[N+10];

    	for( int i = 0 ; i < M ; i++ )
    	{
    		int a , b ; 
    		cin>>a>>b ;

    		g[a].push_back(b);
    		g[b].push_back(a);
    	}
    	vector< int > vis(N+10,0);
    	queue< int > q ; 


    	auto time_bfs = [&]( int T )->void{

    		while( q.size() && T-- )
    		{
    			int sz = q.size();
    			while(sz--)
    			{
    				auto beg = q.front() ; q.pop();

    				for( auto v : g[beg] ){
    					if( vis[v] == 0 )
    					{
                            vis[v] = 1 ;
    						q.push(v);
    					}
    				}
    			}
    		}

    	};	


    	for( int i = 0 ; i < Q ; i++ )
    	{
            int a , b ;
            cin>>a>>b ;


            if( a == 1 )
            {
               if( vis[b] == 0 )
               {
                    vis[b] = 1;
                    q.push(b);
               }
            }
            else if( a == 2 )
            {
                time_bfs(b);
            }
            else
            {
                if(vis[b])
                {
                    cout<<"YES"<<endl;
                }
                else
                {
                    cout<<"NO"<<endl;
                }
            }
    	}
    };
    

    int test = 1 ;
    // cin>>test;
    while(test--)
    solve();
    
    return 0;
}
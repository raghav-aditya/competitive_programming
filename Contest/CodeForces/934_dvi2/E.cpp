/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) begin(x) , end(x) 
#define mask(i) (1LL << (i))
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
vector<int> factorial( int N = MAX )
{
    vector<int>f(N,1);
    for( int i = 2 ; i < N ; i++ )f[i] = (i*f[i-1])%mod;
    return f ;
}
#define oo (int)pow(2L,60)
#define arr array<int,3> 
#define ar array<int,2>

/********** GO DOWN ***********/

/* 
   If the genius trains just as hard.... 
   what chance do I have to beat him? 
*/

int res = -1 ;
int mx = -1 ;

vector<int>ans ;

void dfs( vector<int>g[] , int u , int p , int lv )
{
	for( auto v : g[u] )
	{
		if(v!=p)
		{
			dfs(g,v,u,lv+1);
		}
	}

	if(g[u].size()<=1)
	{
		if( lv > mx )
		{
			mx = lv ;
			res = u ;
		}
	}
}


void go( vector<int>g[] , int u , int p , vector<int>&t )
{
	t.push_back(u);
	for( auto v : g[u] )
	{
		if( v != p )
		{
			go( g , v , u , t );
		}
	}

	if(g[u].size()==1)
	{
		if(ans.size()<t.size())
			ans = t ;
	}
	t.pop_back();
}

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    auto solve = [&]()->void
    {
        int N ;
        cin>>N ;
        vector<int>g[N];
        for( int i = 0 ; i < N-1 ; i++ )
        {
        	int a , b ;
        	cin>>a>>b ;
        	a--;
        	b--;
        	g[a].push_back(b);
        	g[b].push_back(a);
        }


        if( N == 1 )
        {
        	cout<<1<<endl;
        	cout<<1<<" "<<0<<endl;
        	return ;
        }

        auto print = [&]( vector<int>tt)->void{
        	int h = tt.size()+1 ;
        	h /= 2 ;
        	int cnt = 0 ;
        	for( int i = 0 ; i <= h - (tt.size()&1) ; i++ )
        		cnt++;

        	cout<<cnt<<endl ;
        	for( int i = 0 ; i < cnt ; i++ )
        		cout<<tt[h-1]+1<<" "<<i<<endl;
        };

        res = -1 ;
        mx = -1;
        dfs( g , 0 , -1 , 0 );
        vector<int>t;
       	go( g , res , -1 , t );


       	// for( auto x : ans )
       	// 	cout<<x<<" ";
       	// cout<<endl;

       	print(ans);
       	// cout<<endl;
       	// cout<<endl;

    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
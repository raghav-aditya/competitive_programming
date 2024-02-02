#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) begin(x) , end(x) 
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
vector<int> fact( int N = MAX )
{
	vector<int>f(N,1);
	for( int i = 2 ; i < N ; i++ )f[i] = (i*f[i-1])%mod;
	return f ;
}


/********** GO DOWN ***********/

/* 
   If the genius trains just as hard.... 
   what chance do I have to beat him? 
*/

const int SIZE = 1e6 + 100 ;

int _xor[SIZE];

void dfs( int u , int p , int x , vector<array<int,2>>g[] )
{
	for( auto v : g[u] )
	if( v[0] != p )
	{
		int next = v[0] ;
		int nx = x^v[1] ;

		_xor[next] = nx ;

		dfs( next , u , _xor[next] , g );
	}
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
        vector< array< int , 2 > > g[N];


        for( int i = 1 ; i < N ; i++ )
        {
        	int a , b , w ;
        	cin>>a>>b>>w ;
        	a--;
        	b--;
        	// 0 based index 
        	g[a].push_back({b,w});
        	g[b].push_back({a,w});
        }

        dfs( 0 , -1 , 0 , g );
        bool found = 0 ;
        unordered_map< int , vector<int> > mp ;
        for( int i = 0 ; !found && i < N ; i++ )
        for( int j = i+1 ; !found && j < N ; j++ )
        {
        	int val = _xor[i] ^ _xor[j] ;
        	auto x = mp[val];

        	if(x.size())
        	{
        		found = 1 ;
        		cout<<1+i<<" "<<1+j<<" "<<1+x[0]<<" "<<1+x[1]<<endl;
        		break;

        	}
        	
        	mp[val] = { i , j };
        }

        if(!found)
        	cout<<-1<<endl;

	}; 
	
	
	
	
	
	
	
	
    int test = 1 ;
	cin>>test;
	while(test--)
	solve();
	
	return 0;
}
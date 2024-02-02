#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) begin(x) , end(x) 
#define mask(i) (1LL << (i))
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

#define arr array<int,3> 
#define ar array<int,2>

/********** GO DOWN ***********/

/* 
   If the genius trains just as hard.... 
   what chance do I have to beat him? 
*/

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int limit = 10010;

	vector< int > g( limit , 0 );
	vector< int > vis( limit , 0 );
	g[2] = 1 ;
	g[3] = 1 ;

	for( int state = 4 ; state < limit ; state++ )
	{
		for( int i = 0 ; i <= state ; i++ )
		vis[i] = 0 ;		
		for( int left = 0 , right = state-2 ; left <= right ; left++ , right-- ){
			vis[g[left]^g[right]] = 1 ;
		}
		int gn = 0 ;
		while(vis[gn])gn++;
		g[state] = gn ;
	}


	auto solve = [&]()->void
	{
		int N ;
		cin>>N ;
		if(g[N])
			cout<<"Arjuna";
		else
			cout<<"Bhima";
		cout<<endl;
	};
	

		
    int test = 1 ;
	cin>>test;
	while(test--)
	solve();
	
	return 0;
} 
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

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	auto solve = [&]()->void
	{
        int N ;
        cin>>N ;
        vector< int > A(N);
        unordered_map< int , int > mp ;
        for( int i = 0 ; i < N ; i++ )
        {
        	cin>>A[i];
        	mp[A[i]] = i;
        }

        set< int > tool(A.begin(), A.end());

        int look = N ;
        int res = 1 ;
        int st = mp[N];
        int en = mp[N];
        tool.erase(N);


        auto ok = [&]()->bool 
        {
        	assert(tool.size());
        	return (int)tool.size() == (int)*tool.rbegin();
        };

        look--;

        while( look > 0 && tool.size() > 1 )
        {
        	int in = mp[look];
        	if( in < st )
        	{
        		for( int j = st-1 ; tool.size() > 1LL && j >= in ; j-- )
        			tool.erase(A[j]);
        		st = in ;
        		if(ok())
        			res = max( res , N - (int)tool.size() );
        	}
        	else if ( in > en )
        	{
        		for( int j = en+1 ; tool.size() > 1LL && j <= in ; j++ )
        			tool.erase(A[j]);
        		en = in ;

        		if(ok())
        			res = max( res , N - (int)tool.size() );
        	}
			look--;        	
        }

        cout<<res<<endl;
	};
	
	
	
	
	
	
	
	
    int test = 1 ;
	cin>>test;
	while(test--)
	solve();
	
	return 0;
}
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
        vector<int>A(N);
        for( auto &x : A )cin>>x ;
        vector<int>P(N);
        P[0] = A[0];
        for( int i = 1 ; i < N ; i++ )
        P[i] = A[i] + P[i-1] ;
        
        
        if( P[N-1] < 0 )
        {
            cout<<-1<<endl;
            return ;
        }
        
        vector<int> res ;
        
        vector<int>lis(N);
        
        for( int i = 0 ; i < N ; i++ )
        {
            int x = P[i] ;

            if( x < 0 )
            {
                lis[i] = 0 ;
                continue ;
            }

            auto it = upper_bound( all(res) , x ) ;
            
            if( it == res.end() ){
            	lis[i] = res.size() + 1 ;
            	res.push_back(x);
            }
            else{
             *it = x ;
             lis[i] = it-res.begin()+1;
            }
        }
        
        // for( auto x : lis )
        // 	cout<<x<<" ";
        // cout<<endl;
        cout<<N-lis[N-1]<<endl;
	};
	
	
	
	
	
	
	
	
    int test = 1 ;
	cin>>test;
	while(test--)
	solve();
	
	return 0;
}


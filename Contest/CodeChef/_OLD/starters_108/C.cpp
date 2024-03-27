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
// const int mod = pow(10,9)+7 ;
const int mod = LONG_MAX ;
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

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	auto solve = [&]()->void
	{
        int N ;
        cin>>N ;
        string A ;
        cin>>A ;
        int s = 0 ;
        int q = 0 ;
        
        for( auto x : A )
        if( x == '?' )
        q++;
        else
        s+=x-'0';
        
        s %= 9 ;
        
        if( A[0] == '?' )
        {
            cout<<1;
            for( int i = 0 ; i < q-1 ; i++ )
            cout<<0;
            cout<<endl;
        }
        else
        {
            if( s == 0 )
            {
                for( int i = 0 ; i < q-1 ; i++ )
                cout<<1;
                cout<<2<<endl;
            }
            else
            {
                 for( int i = 0 ; i < q ; i++ )
                 cout<<1;
                 cout<<endl;
            }
        }

	};
	

		
    int test = 1 ;
	cin>>test;
	while(test--)
	solve();
	
	return 0;
}
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

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    auto solve = [&]()->void
    {
        int N , K ;
        cin>>N>>K ;
        
        set< int > st ;
        for( int i = 0 ; i < N ; i++ )
        {
        	int x ;
        	cin>>x ;
        	st.insert(x);
        }

        st.insert(0);

        int l = 0 ;
        int h = 10000;


        auto ok = [&]( int m )-> bool 
        {
        	int have = m ;
        	for( int i = 0 ; i <= K ; i++ )
        	{
        		if( st.count(i) )
        			have = m ;

        		if( have <= 0 )
        		{
        			return 0 ;
        		}
        		have--;
        	}

        	for( int i = K-1 ; i >= 0 ; i-- )
        	{
        		if(st.count(i))
        			have = m ;

        		if( have <= 0 )
        			return 0;
        		have--;
        	}
        	return 1 ;
        };

        while( l < h )
        {
        	int m = (l+h)>>1 ;
        	if( ok(m) )
        		h = m-1 ;
        	else
        		l = m+1 ;
        }



        auto clean = [&]( int d )->int{
        	for( int m = d-1 ; m <= d+1 ; m++ )
        	{
        		if( m >= 0 && ok(m) )
        			return m;
        	}
        	return d ;
        };


        cout<<clean(l)<<endl;

    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
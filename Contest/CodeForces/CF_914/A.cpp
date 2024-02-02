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
        int a , b ;
        cin>>a>>b ;

        int kx , ky , qx , qy ;
        cin>>kx>>ky>>qx>>qy ;


        set< ar > A , B ;

        for( int p = 4 ; p < 8 ; p++ )
        {
        	int nx = kx + dx[p]*a ;
        	int ny = ky + dy[p]*b ;

        	A.insert({nx,ny});

			nx = kx + dx[p]*b ;
	    	ny = ky + dy[p]*a ;

        	A.insert({nx,ny});
        }


        for( int p = 4 ; p < 8 ; p++ )
        {
        	int nx = qx + dx[p]*a ;
        	int ny = qy + dy[p]*b ;

        	B.insert({nx,ny});
			nx = qx + dx[p]*b ;
	    	ny = qy + dy[p]*a ; 
        	B.insert({nx,ny});
        }

        int res = 0 ;
        for( auto x : A )
        {
        	if(B.count(x))
        		res++;
        }

        cout<<res<<endl;

        // // cout<<endl;
        // // cout<<res<<endl;

        // cout<<endl;
        // cout<<endl;
        // cout<<endl;

    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
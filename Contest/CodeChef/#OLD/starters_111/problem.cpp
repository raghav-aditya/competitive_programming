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
    
    auto count_multiples = [&]( int N , int x )-> int 
    {
    	return (N/x) ;
    };


    auto count_multiples_in_range = [&]( int L , int R , int x )->int 
    {
    	return count_multiples( R , x ) - count_multiples( L-1 , x );
    };

    auto solve = [&]()->void
    {
        int L , R , P ;
        cin>>L>>R>>P ;

        int np = P ;

        int t = 0 ;

        // int k = 1 ;

        t = count_multiples_in_range( L , R , np );

        // while( np <= R )
        // {
        // 	if(k&1)
        // 	t += count_multiples_in_range( L , R , np );
        // 	else
        // 	t -= count_multiples_in_range( L , R , np );

        // 	k++ ;
        // 	k%=2 ;
        // 	np *= P ;
        // }

        // cout<<t<<endl;

        if(t&1)
        	cout<<"First"<<endl;
        else
        	cout<<"Second"<<endl;

    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
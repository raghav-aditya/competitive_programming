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
    
    vvi E( 300 , vi(300 , 0));
    auto O = E ;

    O[0][0] = 1 ;

    E[0][0] = 1 ;    E[0][1] = 0 ;
    E[1][0] = 0 ;    E[1][1] = 1 ;

    auto fill_odd = [&]( int p )->void 
    {
        if( p+1 >= 300 )
            return ; 

        int odd = p/2 ;
        odd = odd&1 ;

        {
                O[p][p]   = 0 ; O[p][p+1]   = 1 ;
                O[p+1][p] = 0 ; O[p+1][p+1] = 1 ;   
        }


        for( int j = 0 ; j < p ; j++ )
        {

            O[p][j] = j&1 ;
            O[p+1][j] = j&1 ;



            O[j][p] = 1 ^ O[p][j] ;
            O[j][p+1] = 1 ^ O[p+1][j] ;
        }
    };

    auto fill_even = [&]( int p )->void 
    {
        if( p+1 >= 300 )
            return ; 

        E[p][p]   = 0 ; E[p][p+1]   = 1;
        E[p+1][p] = 1 ; E[p+1][p+1] = 0 ;   


        for( int j = 0 ; j < p ; j++ )
            E[p][j] = E[p+1][j] = 1 ;
    };

    for( int p = 1 ; p < 300 ; p++ )
    {
    	if(p&1)
    	{
    		fill_odd( p );
    	}
    	else
    	{	
    		fill_even( p );
    	}
    }


    auto print = [&]( vvi &A , int N )
    {
    	int even = 2 ;
    	int odd = 1 ;
    	for( int i = 0 ; i < N ; i++ )
    	{
    		for( int j = 0 ; j < N ; j++ )
    		{
    			if(A[i][j])
    			{
    				cout<<odd<<" ";
    				odd+=2 ;
    			}
    			else
    			{
    				cout<<even<<" ";
    				even+=2;
    			}
    		}
    		cout<<endl;
    	}

    };

    auto solve = [&]()->void
    {
       int N ;
       cin>>N ;
      

       if( N&1 )
       	print(O,N);
       else
       	print(E,N);
    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
/*
You have a country with n states, each with some given population, 
let’s denote that with an integer array population[].
Everyone in the country is infected with a virus, and the country has k doctors available to treat everyone.

What’s the ‘most fair’ distribution of doctors for each state, 
so that the ratio of (doctors[i]/population[i]) for the ith state, the minimum value of this ratio is as high as possible.

n ~ 1e5
k ~ 1e9, k >= n
population[i] ~ 1e9


*/  







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
        
       long double l = 0 ;
       long double h = pow(10LL,16);

       int N ;
       cin>>N ;
       int k ;
       cin>>k ;
       vector<int>P(N,0);
       for( auto &x : P )cin>>x ;

       auto ok = [&]( long double m )->bool
        {
            
            int count = 0 ; // number of doctors we need 
            for( auto x : P )
            {
                long double doc = x * m ;
                count += ceil(doc);
            }

            if(count<= k )
                return 1 ;
            else
                return 0 ;
        };
    
       while( abs(h-l) > pow((long double)10,-8) )
       {
           long double s = l + h ; 
           s /= (long double)2.000000 ;

           long double m = s ;

           if( ok(m) )
             l = m ;
           else
             h = m ;
       }
       std::cout << std::fixed << std::setprecision(6) << l << std::endl;
    };

    solve();
    
    return 0;
}

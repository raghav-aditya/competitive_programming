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
        unordered_map< int , vector<int> > mp ;
        int N ;
        cin>>N ;
        vector<int>A(N);
        for( auto &x : A )cin>>x ;

        for( int i = 0 ; i < N ; i++ )
        {
            mp[A[i]].push_back(i);
        }   

        int res = 0 ;

        for( int i = N-1 ; i >= 0 ; i-- )
        {
            int x = A[i];
            if( x > 3 && ((x % (x-3)) == 0) )
            {
                int y = x/(x-3);
                res += mp[y].end() - lower_bound( mp[y].begin() , mp[y].end() , i+1 );
            }
        }

        cout<<res<<endl;
    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
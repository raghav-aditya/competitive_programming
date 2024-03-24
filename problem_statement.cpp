/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) begin(x) , end(x) 
#define on(i) (1LL << (i) )
#define mask(i) (on(i)-1)
#define vi vector<int>
#define vvi vector<vi>
#define arr array<int,3> 
#define ar array<int,2>

const int mod = pow(10,9)+7 ;
const int MAX = pow(10,5)+1 ;
const int dx[8] = { 1 , -1 , 0 , 0 , 1 , 1 , -1 , -1 } ;
const int dy[8] = { 0 , 0 , 1 , -1 , 1 , -1 , 1 , -1 } ;
int mod_pow( int a , int b ){if( a == 0 || a == 1 ) return a ; if( b == 0 )return 1 ; int ha = mod_pow( a , b/2 ); ha *= ha; ha %= mod ; if( b&1 ) ha *= a ; return ha%mod;}
int inverse( int a )
{
    return mod_pow(a,mod-2);
}


/********** GO DOWN ***********/

/* 
   If the genius trains just as hard.... 
   what chance do I have to beat him? 
*/

int cnt = 0 ;

int dfs( vector<int>g[] , int u , int p )
{
    int res = 1 ;
    for( auto v : g[u] )
    {
        if( v != p )
        {
            int sz = dfs( g , v , u );

            res += sz ;

            if( sz%2 == 0)
            {
                cnt++;
                res -= sz ;
            }
        }
    }
    return res ;
}

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    int N ;
    cin>>N ;
    vector<int>g[N];
    for( int i = 0 ; i < N- 1 ; i++ )
    {
        int a , b ;
        cin>>a>>b ;
        a--;
        b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    if( N&1 )
    {
        cout<<-1<<endl;
        return 0 ;
    }


    int res = dfs( g , 0 , -1 );

    if( res%2 )
    {
        cout<<-1<<endl;
        return 0;
    }

    cout<<cnt<<endl;

    return 0;
}
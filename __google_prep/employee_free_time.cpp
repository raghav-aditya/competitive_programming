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
    

    vector< vector< vector<int> > > A = {
    	{{1,3},{6,7}},
    	{{2,4}},
    	{{2,5},{9,12}}
    };
    

    map< int , int > mp ;

    for( auto x : A )
    {
    	for( auto i : x )
    	{
    		mp[i[0]]++;
    		mp[i[1]]--;
    	}
    }

    vector< vector<int> > res ;

    int t = 0 ;
    int st = -1 ;

    int N = A.size();

    for( auto x : mp )
    {
    	int a = x.first ;
    	int b = x.second ;

    	if( st != -1 )
    	{
    		res.push_back({N-t,st,a});
    	}

    	t += b ;
    	st = a ;
    }

    sort( res.begin() , res.end() );

    for( auto x : res )
    {
    	cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
    }

    return 0;
}
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
        int N ;
        cin>>N ;

       	vector<int>A(N); for( auto &x : A )cin>>x ;

       	vector<int>mark(N,1);

       	int cnt = 1 ;

       	map< int , vector<int> > mp ;
       	for( int i = 0 ; i < N ; i++ )
       		mp[A[i]].push_back(i);


       	auto del = [&]( int i )->int
       	{
       		int how_many = 0 ;
       		for( int j = i-1 ; j <= i+1 ; j++ )
       		{	
       			if(j>=0&&j<N)
       			how_many += mark[j] ;
       		}

       		switch( how_many )
       		{
       			 case 0:
       			 	return 0 ;

       			 case 1:
       			 	return -1 ;

       			 case 2:
       			 	return 0 ;
       			 case 3: 
       			 	return 1 ;
       		}
       		return 0;
       	};

       	int res = 0 ;
       	for( auto x : mp )
       	{
       		for( auto in : x.second )
       		{
       			cnt += del( in );
       			mark[in] = 0 ;
       		}

       		cout<<cnt<<" ";
       		res += cnt ;
       	}

       	cout<<endl;
       	cout<<res<<endl;
    	
    	cout<<endl;

    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}	
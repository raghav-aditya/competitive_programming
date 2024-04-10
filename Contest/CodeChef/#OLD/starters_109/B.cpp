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
        vector<int>A(N);
        for( auto &x : A )cin>>x ;

        multiset< int > E , O ;

    	for( auto &x : A ){
    		if( x&1 )
    			O.insert(x);
    		else
    			E.insert(x);
    	}

    	
    	vector<int>res(N,0);
    	int curr = 0 ;


    	if( E.size()&1 || O.size()&1 )
    	{
    		cout<<-1<<endl;
    		return ;
    	}
    	
    	while(E.size())
    	{
    		ar a = { *E.begin() , *E.rbegin() };
    		int s = a[0] + a[1] ;
    		
    		int p1 = s/2 ;
    		int p2 = a[1] - p1 ;

    		res[curr] = p1;
    		res[curr+N/2] = p2;

    		curr++;

    		E.erase(E.find(a[0]));
    		E.erase(E.find(a[1]));
    	}


    	while(O.size())
    	{
    		ar a = { *O.begin() , *O.rbegin() };
    		int s = a[0] + a[1] ;
    		
    		int p1 = s/2 ;
    		int p2 = a[1] - p1 ;

    		res[curr] = p1;
    		res[curr+N/2] = p2;

    		curr++;

    		O.erase(O.find(a[0]));
    		O.erase(O.find(a[1]));
    	}

    	for( auto x : res )
    		cout<<x<<" ";
    	cout<<endl;
    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
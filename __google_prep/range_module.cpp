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


class range_module
{
	map< int , int > mp ;
public:

	void insert( int l , int r )
	{
		auto it = mp.upper_bound( l );

		// [ prev_st , pre_en ] + [ l , r ] + [ next_st  , next_en ] 

		if( it != mp.begin() && prev(it)->second >= l )
			--it ;

		for( ; it != mp.end() && it->first <= r ; mp.erase(it++) )
		{
			l = min( l , it->first );
			r = max( r , it->second);
		}

		mp[l] = r ;
	}

	bool get( int p )
	{
		auto it = mp.upper_bound(p);

		if( it == mp.begin() )
			return 0 ;

		it--;
		return p >= it->first && p <= it->second ;
	}

	void print()
	{
		for( auto x : mp )
		{
			int a = x.first ;
			int b = x.second ;

			cout<<"[ "<<a<<", "<<b<<" ]"<<endl;
		}
		cout<<endl;
	}
};






























// d
// 2-5
// 9-13
// Points Queried

// 0 -> False
// 2 -> True
// 10 -> True








int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    range_module tool;
    tool.insert( 2 , 5 );
    tool.print();
    tool.insert( 9 , 13);
    tool.print();
    tool.insert( 3 , 7 );
    tool.print();
    cout<<tool.get(9)<<endl;

    return 0;
}
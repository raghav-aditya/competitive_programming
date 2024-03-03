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

class seg_tree
{
	vector<int>T ;
	int N ;

public:
	seg_tree ( const int sz )
	{
		this->N = sz ;
		T.resize(2*N,0);
	}

	void add( int p )
	{
		T[p+=N] = 1 ;

		for( ; p >>= 1 ; )
		{
			T[p] = T[2*p] + T[2*p+1];
		}
	}

	int get( int a , int b )
	{
		int res = 0 ;
		for( a += N , b += N+1 ; a < b ; a >>= 1 , b>>= 1 )
		{
			if(a&1) res += T[a++];
			if(b&1) res += T[--b];
		}
		return res;
	}

};

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    auto solve = [&]()->void
    {
        int N;
        cin>>N ;
        vector<int>A(N);
        for( auto &x : A )
        	cin>>x ;


        for( auto &x : A )
        {
        	x--;
        }

        unordered_map< int , int > mp;
        for( int i = 0 ; i < N ; i++ )
        {
        	mp[A[i]] = i ;
        }


        set< int > zero ;
        for( int i = 0 ; i < N ; i++ ){
        	zero.insert(i);
        }

        seg_tree st(N);

        int res = min( 2LL , N );

        for( int i = 0 ; i < N ; i++ )
        {
        	int in = mp[i];

        	zero.erase(in);
        	st.add(in);

        	if(zero.size() < 2 )
        		continue ;

        	int a = *zero.begin();
        	int b = *zero.rbegin();

        	// cout<<a<<" "<<b<<" "<<st.get(a,b)<<endl;

        	res = max( res , 2 + st.get(a,b) );
        }

        cout<<res<<endl;

    };
    


    solve();
    
    return 0;
}
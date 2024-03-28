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

     	int Q ;
     	cin>>Q ;

     	vector<int>P(N+1,0LL);
     	for( int i = 0 ; i < N ; i++ )
     		P[i+1] = A[i] + P[i];

     	auto range = [&]( int a , int b )-> int 
     	{
     		return P[b+1] - P[a];
     	};



     	auto task = [&]( int L , int U )-> int 
     	{

     		int l = L ;
     		int h = N-1 ;

     		int mx = INT_MIN ;
     		int res = L-1;


     		auto f = [&]( int m)-> int 
     		{
     			int sum = range( L-1 , m );
     			return sum*U - ((sum*(sum-1))/2);
     		};

     		while( l < h )
     		{
     			int m = (l+h)>>1 ;

     			int y2 = f(m);
     			int y1 = f(m-1);

     			if( y1 == y2 )
     				l = h = m ;


     			if( y2 > y1 )
     				l = m+1;
     			else
     				h = m-1;
     		}

     		for( int m = l+1 ; m >= l-1 ; m-- )
     		{
     			if(m >= L-1 && m < N )
     			{
     				if( f(m) >= mx )
     				{
     					mx = f(m);
     					res = m ;
     				}
     			}
     		}

     		return res+1;
     	};

     	for( int i = 0 ; i < Q ; i++ )
     	{
     		int l , u ;
     		cin>>l>>u ;

     		cout<<task( l , u )<<" ";
     	}

     	cout<<endl;
    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}


// 
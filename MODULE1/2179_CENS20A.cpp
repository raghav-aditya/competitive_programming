/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 

 If the genius trains just as hard.... 
 what chance do I have to beat him? 

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) begin(x) , end(x) 
#define mask(i) (1LL << (i))
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

#define arr array<int,3> 
#define ar array<int,2>

/********** GO DOWN ***********/


class seg_tree {

int N ;
vector<int>A;
vector<int>T;
vector<int>lazy ;
public:

	void build( int v , int TL , int TR ){
		if( TL > TR )
			return ;
		if( TL == TR )
		{
			T[v] = A[TL];
			return ;
		}
		int mid = (TL+TR)>>1;
		build(2*v+1 , TL , mid );
		build(2*v+2 , mid+1, TR);

		T[v] = T[2*v+1] + T[2*v+2] ;
	}

	seg_tree( vector<int>t )
	{
		N = t.size();
		A.resize(N);
		T.resize(4*N);
		lazy.resize(4*N);

		build(0,0,N-1);
	}

	void push(int v , int TL , int TR )
	{
		int len = TR-TL+1 ;
		if(lazy[v])
		{
			T[v] = len - T[v] ;
			lazy[v] = 0 ;

			if( len > 1 )
			{
				lazy[2*v+1] ^= 1 ;
				lazy[2*v+1] ^= 1 ;
			}
		}
	}

	void pull( int v , int TL , int TR )
	{
		if( TL != TR )
		{
			T[v] = T[2*v+1] + T[2*v+2] ;
		}
	}

	void update( int v , int TL , int TR , int AL , int AR )
	{
		if( TL > TR )
			return ;
		int mid = (TL+TR)>>1 ;
		if( TR < AL || AR < TL )
			return ;

		push(v,TL,TR);

		if( AL <= TL && TR <= AR )
		{
			lazy[v] = 1 ;
			return ;
		}

		update( 2*v+1 , TL , mid , AL , AR );
		update( 2*v+2 , mid+1,TR , AL , AR );

		pull(v,TL,TR);
	}


	int sum( int v , int TL , int TR , int AL , int AR )
	{

		if(TL > TR || v >= 4*N ) 
			return 0 ;
		if( AR < TL || TR < AL )
			return 0 ;

		push(v,TL,TR);
		
		if( AL <= TL && AR <= TR )
			return T[v] ;
		int mid = (TL+TR)>>1 ;
		return sum( 2*v+1 , TL , mid , AL , AR ) 
			 + sum( 2*v+2 , mid+1,TR , AL , AR );
	}


};





int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	vector< int > t  = { 0 , 0 , 0 , 0 , 0 };
	int N = t.size();
	seg_tree st(t);
	st.update(0,0,N-1,0,2);

	for( int i = 0 ; i < N ; i++ )
		cout<<st.sum(0,0,N-1,i,i)<<" ";
	cout<<endl;

	// auto solve = [&]()->void
	// {
		
	// };
	

		
    // int test = 1 ;
	// cin>>test;
	// while(test--)
	// solve();
	
	return 0;
}
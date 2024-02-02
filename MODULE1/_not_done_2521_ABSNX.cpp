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

/* 
   If the genius trains just as hard.... 
   what chance do I have to beat him? 
*/

class seg_tree
{
	int N ;
	vector< ar > T ;

	ar pull( ar a , ar b )
	{
		if( a[0] == b[0] )
			return { a[0] , a[1] + b[1] };
		else if( a[0] < b[0] )
			return a ;
		else
			return b ;
	}

public:

	seg_tree( const vector<int>&A )
	{
		this->N = A.size();
		T.resize(2*N);
		for( int i = 0 ; i < N ; i++ )
			T[i+N] = { A[i] , 1 };

		for( int i = N-1 ; i > 0 ; i-- )
		{
			T[i] = pull(T[2*i] , T[2*i+1]);
		}
	}

	int get( int a , int b )
	{
		map< int , int > mp ;
		for( a += N , b += N+1 ; a < b ; a >>= 1 , b >>= 1 )
		{
			if(a&1){
				auto k = T[a++];
				mp[k[0]] += k[1];
			} 
			if(b&1){
				auto k = T[--b];
				mp[k[0]] += k[1];
			}
		}
		return (*mp.begin()).second;
	}

};

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	auto solve = [&]()->void
	{
		int N ;
		cin>>N ;
		vector< int > A(N), ngr(N) , ngl(N);
		for( auto &x : A )cin>>x ;

		stack<int>st ;
		for( int i = 0 ; i < N ; i++ )
		{
			while(st.size()&&A[i]>=A[st.top()])st.pop();
			if(st.size())
				ngl[i] = st.top();
			else
				ngl[i] = -1;

			st.push(i);
		}

		while(st.size())st.pop();

		for( int i = N-1 ; i >= 0 ; i-- )
		{
			while(st.size()&&A[i]>=A[st.top()])st.pop();
			if(st.size())
				ngr[i] = st.top();
			else
				ngr[i] = N ;

			st.push(i);
		}

		seg_tree seg_t(A);

		// int res = 0 ;

		for( int i = 0 ; i < N ; i++ )
		{
			int lt = ngl[i] ;
			int rt = ngr[i] ;

			cout<<lt<<" "<<rt;
			cout<<" -> "<<seg_t.get(lt+1,i)<<" , ";
			cout<<seg_t.get(i,rt-1)<<endl;

			// res += seg_t.get(lt+1,i);
			// res += seg_t.get(i,rt-1);
		}

		cout<<endl;
		cout<<endl;
		cout<<endl;
		// cout<<res<<endl;
	};
	

		
    int test = 1 ;
	cin>>test;
	while(test--)
	solve();
	
	return 0;
}
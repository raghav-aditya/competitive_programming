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


class sweep_line
{
	vector<int>T ;
	int N;
public:
	sweep_line(int size)
	{
		this->N = size ;
		T.resize(N,0);
	}

	void update( int a , int b )
	{
		T[a]++;
		if(b+1<N)
			T[b+1]--;
	}

	void print()
	{
		cout<<1<<" ";
		for( int i = 1 ; i < N ; i++ ){
			T[i] += T[i-1];
			cout<<T[i]<<" ";
		}
		cout<<endl;
	}

	int size()
	{
		return N ;
	}
};

int dfs( int u , int p , vector<int>g[] , sweep_line &tool , int level = 0 )
{
	int s = 0 ;
	s++;
	for( auto v : g[u] )
	{
		if( v != p )
		{
			s += dfs( v , u , g , tool , level+1 );
		}
	}
	int st = level;
	int en = tool.size() - s ;
	tool.update(st,en);
	return s ;
}

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    auto solve = [&]()->void
    {
        int N ; cin>>N ;
        vector<int>g[N];
        vector<int>inD(N,0);
        vector<int>sum(N,0);

        for( int i = 0 ; i < N-1 ; i++ )
        {
        	int a , b ; cin>>a>>b ;
        	a--;b--;
        	g[a].push_back(b);
        	inD[b]++;
        }

        sweep_line tool(N);

        int root = -1 ;
        for( int i = 0 ; i < N ; i++ )
        	if(inD[i] == 0 )
        	{
        		root = i ;
        		break;
        	}

        dfs( root , -1 , g , tool );

        tool.print();
    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
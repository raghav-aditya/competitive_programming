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

int randomfunc(int j) 
{ 
    return rand() % j; 
} 


class seg_tree {
	vector<int>T ;
	int N ;
public:
	seg_tree( vector<int>&A )
	{
		this->N = A.size();
		T.resize(N+1,0);
		for( int i = 0 ; i < N ; i++ )
			T[i+1] = T[i] ^ A[i];
	}

	int get( int a , int b )
	{
		return T[b+1] ^ T[a];
	}
};


bool ok( vector<int>&A , int N , int k )
{
	  	seg_tree tool( A );

  		auto print = [&]( int a , int b )-> void {
  			for( int i = a ; i <= b ; i++ )
  				cout<<A[i]<<" ";
  			cout<<endl;
  		};

		k *= 2 ;

		unordered_map< int , ar > F , S ;

		for( int i = 0 ; i+k-1 < N ; i++ )
		{
			int a = i ;
			int b = i+k-1;

			int c = i+N;
			int d = c+k-1;


			F[tool.get(a,b)] = {a,b};
			S[tool.get(c,d)] = {c,d};
		}  			

		for( auto x : F){
			if( S.count(x.first) )
			{
				int a = x.second[0];
				int b = x.second[1];

				int c = S[x.first][0];
				int d = S[x.first][1];

				print(a,b);
				print(c,d);
				return 1 ;
				break ;
			}
		}
		return 0 ;
}

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    srand(time(0)); 

    auto solve = [&]()->void
    {
  
  		int N , k ;
  		cin>>N>>k ;
  		vector<int>A(2*N,0);
  		for( auto &x : A )cin>>x ;


  		for( int i = 0 ; i < 1000 ; i++ )
  		{
  			random_shuffle(A.begin(), A.begin()+N , randomfunc);
  			random_shuffle(A.begin()+N, A.end() , randomfunc);  
  			if(ok( A , N , k )){
  				return ;
  			}
  		}
    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}




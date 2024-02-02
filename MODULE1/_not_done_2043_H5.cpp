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

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	auto solve = [&]()->void
	{
		
	};
	

		
    int test = 1 ;
	cin>>test;
	while(test--)
	solve();
	
	return 0;
}



/*
reference: 

1. https://www.codechef.com/viewsolution/1012194054
2. https://www.codechef.com/viewsolution/35461606
3. https://www.codechef.com/viewsolution/10464606
4. https://www.codechef.com/viewsolution/7096712
5. https://www.codechef.com/viewsolution/2976851
6. https://www.codechef.com/viewsolution/111218
7. https://www.codechef.com/viewsolution/108228
8. https://www.codechef.com/viewsolution/100927
9. https://www.codechef.com/viewsolution/100825 [ best ]
*/
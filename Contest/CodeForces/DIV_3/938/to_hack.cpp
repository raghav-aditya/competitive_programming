#include<bits/stdc++.h>
using namespace std;

#define int long long 

int32_t main(){

	long long my_k = pow(10LL, 15);
	int N = 2*pow(10LL,5);
	int v = pow(10LL,9);

	cout<<1<<endl;
	cout<<N<<" "<<my_k<<endl;

	for( int i = 0 ; i < N ; i++ ){
		cout<<v;
		if( i != N-1 )
			cout<<" ";
	}
	cout<<endl;
} 
	

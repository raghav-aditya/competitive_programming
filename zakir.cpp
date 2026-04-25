/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long 



int32_t main() {

	int a = 99999 ;
	for( int i = 0 ; i < 100000 ; i++ )
	{
		int b = a-i;

		int res = a*b ;

		auto bb = to_string(res);
		auto c = bb ;
		reverse( c.begin() , c.end() );

		if( bb == c )
		{
			cout<<a<<" "<<b<<" "<<res<<endl;

			break ;
		}
	}


	// int a = 999999;
	// int b = 999001;
	// cout<<a<<" "<<b<<" "<<a*b<<endl;


	// a = 999 ;
	// b = 911 ;
	// cout<<a<<" "<<b<<" "<<a*b<<endl;


return 0;
}   
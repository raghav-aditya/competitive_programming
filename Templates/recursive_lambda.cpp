#include <bits/stdc++.h>
using namespace std ;

int main(){


auto f = [&]( auto self , int a )->int{
	if( a <= 0 )
		return 0 ;
	return 1 + self( self , a-1 );
};

cout<<f(f,10)<<endl;

	return 0;
}
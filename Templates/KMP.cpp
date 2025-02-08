#include <bits/stdc++.h>
using namespace std ;

vector<int> find( vector<int>&A )
{
	int i =1 ;
	vector<int>lps(A.size(),0);
	int len = 0 ;

	while( i < A.size() )
	{
		if( A[i] == A[len] )
		{
			lps[i++] = ++len ;
		}
		else
		{
			if( len == 0 )
				lps[i++] = 0;
			else
				len = lps[len-1];
		}
	}

}

int main()
{
	vector<int>A ;
	auto lps = find(A);
	return 0 ;
}
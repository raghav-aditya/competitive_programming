#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double


ld delta = pow(10,-8);

ld solve(){

	    int N ;
    	cin>>N ;
    	vector<int>P(N),S(N);

    	for( auto &x : P )cin>>x ;                            
    	for( auto &x : S )cin>>x ;

    	long double l = -pow(10,10);
    	long double h =  pow(10,10);

    	auto f = [&]( long double m )-> ld 
    	{
    		long double mx = 0 ;

    		for( int i = 0 ; i < N ; i++ )
    			mx = max( mx , abs(m-P[i]) + S[i] );
    		return mx ;
    	};

    	while(abs(l-h)>3*delta)
    	{
    		auto m = l+h ;
    		m/= 2 ;

    		auto fm = f(m);
    		auto fm_1= f(m+delta);

    		if( fm_1 > fm ) // increasing slope
    			h = m ;
    		else            // decreasing slope
    			l = m ;
    	}

    	return l;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin>>test;
    while(test--)
        cout<<fixed<<setprecision(6)<<solve()<<endl;

return 0;
}   
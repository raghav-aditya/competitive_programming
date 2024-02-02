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

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    


    auto solve = [&]()->void
    {
        int N , D ;
        cin>>N>>D ;
        vector<int>mx(N),mn(N);
        for( auto &x : mx )cin>>x ;
        for( auto &x : mn )cin>>x ;


        for( int i = 1 ; i < N ; i++ )
        {
        	if( mn[i] > mn[i-1] || mx[i] < mx[i-1] )
        	{
        		cout<<"NO"<<endl;
        		return ;
        	}
        }

    	if( mx[0] != mn[0] )
    	{
    		cout<<"NO"<<endl;
    		return ;
    	}

        vector<ar> future ;
        vector<int>res;
        res.push_back(mx[0]);

        for( int i = 1 ; i < N ; i++ )
        {

        	vector<ar>temp;

        	if( mx[i] > mx[i-1] )
        		temp.push_back({ mx[i] , i });
        	if( mn[i] < mn[i-1] )
        		temp.push_back({ mn[i] , i });

        	if(temp.size()>1)
        	{
        		cout<<"NO"<<endl;
        		return ;
        	}

        	if(temp.size())
        		future.push_back(temp.front());
        }


        int ls_in = 0 ;
        int ls_val = mn[0];

        for( int b = 0 ; b < (int)future.size() ; b++ )
        {
        	int curr_in = future[b][1];
        	int curr_val = future[b][0];

        	bool is_greater = (curr_val >= ls_val) ;

        	for( ls_in++ ; l <= curr_in ; p++ )
        	{
        		if(is_greater)
        			ls_val = min( {ls_val+D , mx[p] , curr_val} );
        		else
        			ls_val = max( {ls_val-D , mn[p] , curr_val} );

        		res.push_back(ls_val);
        	}

        	if( ls_val != curr_val )
        	{
        		cout<<"NO"<<endl;
        		return ;
        	}

        }

    	while(res.size()<N)
    		res.push_back(ls_val);

    	cout<<"YES"<<endl;
    	for( auto x : res )
    		cout<<x<<" ";
    	cout<<endl;
    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}
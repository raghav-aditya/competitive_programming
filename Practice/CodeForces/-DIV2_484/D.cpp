/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) begin(x) , end(x) 
#define on(i) (1LL << (i) )
#define mask(i) (on(i)-1)
#define vi vector<int>
#define vvi vector<vi>
#define arr array<int,3> 
#define ar array<int,2>

const int mod = pow(10,9)+7 ;
const int MAX = pow(10,5)+1 ;
const int dx[8] = { 1 , -1 , 0 , 0 , 1 , 1 , -1 , -1 } ;
const int dy[8] = { 0 , 0 , 1 , -1 , 1 , -1 , 1 , -1 } ;
int mod_pow( int a , int b ){if( a == 0 || a == 1 ) return a ; if( b == 0 )return 1 ; int ha = mod_pow( a , b/2 ); ha *= ha; ha %= mod ; if( b&1 ) ha *= a ; return ha%mod;}
int inverse( int a )
{
    return mod_pow(a,mod-2);
}


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
    

    int N ;
    cin>>N ;
    vector<int>A(N);
    for( auto &x : A )
    	cin>>x ;

    auto ok = [&]( int k )->bool{
    	set< int > st ;

    	int cnt = 0 ;
    	for( auto x : A )
    	{
    		if( x < k )
    		{
    			cnt++;
    		}
    		else
    		{
    			if(cnt)
    			st.insert(cnt);
    			cnt = 0 ;
    		}
    	}

    	if(cnt)
    		st.insert(cnt);

    	cout<<*st.begin()<<" ";
    	return st.size() == 1 ; 
    };

    int l = *min_element( A.begin() , A.end() );
    int h = *max_element( A.begin() , A.end() );
    for( int k = l+1 ; k <= h ; k++ )
    {
    	cout<<k<<" -> ";
    	if( ok(k) )
    		cout<<"YES"<<endl;
    	else
    		cout<<"NO"<<endl;
    }
    
    return 0;
}
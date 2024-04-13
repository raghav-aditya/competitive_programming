/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

#define int long long
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define all(x) begin(x) , end(x) 
#define on(i) (1LL << (i))
#define mask(i) (on(i)-1LL)
#define vi vector<int>
#define vvi vector<vi>
const int mod = pow(10,9)+7 ;
const int MAX = pow(10,5)+1 ;
const int dx[8] = { 1 , -1 , 0 , 0 , 1 , 1 , -1 , -1 } ;
const int dy[8] = { 0 , 0 , 1 , -1 , 1 , -1 , 1 , -1 } ;
int mod_pow( int a , int b , int md = mod )
{
    if( a == 0 || a == 1 ) return a ;
    if( b == 0 )return 1 ;
    int ha = mod_pow( a , b/2 ); ha *= ha; ha %= md ; if( b&1 ) ha *= a ;
    return ha%md ;
}
int inverse( int a )
{
    return mod_pow(a,mod-2);
}
vector<int>factorial_ ; 
vector<int> factorial( int N = MAX )
{
    vector<int>f(N,1);
    for( int i = 2 ; i < N ; i++ )f[i] = (i*f[i-1])%mod;
    return f ;
}
void init_factorial(){ if(factorial_.size()==0)factorial_ = factorial(); }
#define oo (int)pow(2L,60)
#define arr array<int,3> 
#define ar array<int,2>

int nCr( int N , int R )
{
    if(factorial_.size()==0) factorial_ = factorial();
    int res = factorial_[N]; res *= inverse( factorial_[R] );  
    res = (res%mod+mod)%mod; res *= inverse( factorial_[N-R] ); 
    res = (res%mod+mod)%mod; return res ;
}


/********** GO DOWN ***********/

/* 
   If the genius trains just as hard.... 
   what chance do I have to beat him? 
*/

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void{
        int N , k ;
        cin>>N>>k ;
        vector<int>A(N);


        vector<int>P(k),Q(k);
        for( auto &x : P )
        	cin>>x ;
        for( auto &x : Q )
        	cin>>x ;

        ar f = { 1 , (N+1)/2 };
        ar s = { 1 + f[1] , N };

        // cout<<f[0]<<" "<<f[1]<<endl;
        // cout<<s[0]<<" "<<s[1]<<endl;

        auto is_merge = [&]( ar a , ar b )->bool
        {
        	vector<ar>tt = { a , b };
        	sort(all(tt));
        	a = tt[0];
        	b = tt[1] ;
        	return a[1] >= b[0] ;
        };

        map< int , int > first_map , second_map , both_map ;

        auto is_inside = [&]( ar t , ar p )-> bool
        {
        	if( t[0] <= t[1] )
        	{
        		if( p[0] <= p[1] )
        		{
        			return is_merge( t , p );
        		}
        		else
        		{
        			ar p1 = { P[1] , N };
        			ar p2 = { 1 , P[0] };
        			
        			if( is_merge( t , p1 ) )
        				return 1 ;

        			if( is_merge( t , p2 ) )
        				return 1 ;
        			
        			return 0;
        		}
        	}
        	else
        	{
        		if( p[0] <= p[1] )
        		{
        			swap( t , p );

        			ar p1 = { P[1] , N };
        			ar p2 = { 1 , P[0] };
        			
        			if( is_merge( t , p1 ) )
        				return 1 ;

        			if( is_merge( t , p2 ) )
        				return 1 ;
        			
        			return 0;

        		}
        		else
        		{
        			swap( t[0] , t[1] );
        			swap( p[0] , p[1] );

        			if( is_merge( t , p ) )
        				return 1 ;
        			return 0;
        		}
        	}
        };


        map< int , vector<int> > start_boundry , end_boundry;

        for( int i = 0 ; i < k ; i++ )
        {
        	int a = P[i];
        	int b = Q[i];

        	start_boundry[a].push_back(i);
        	end_boundry[b].push_back(i);

        	ar tt = { a , b };


        	if( is_inside( f , tt )){
        		// cout<<f[0]<<" "<<f[1]<<" | "<<a<<" "<<b<<endl;
        		first_map[i]++;
        	}

        	if( is_inside( s , tt )){
        		// cout<<s[0]<<" "<<s[1]<<" | "<<a<<" "<<b<<endl;
        		second_map[i]++;
        	}

        	if( first_map[i] && second_map[i] )
        		both_map[i]++;
        }


        // cout<<endl;
        // cout<<endl;
        // cout<<endl;

        // auto print_ = [&]( map< int , int > &ttt )->void
        // {
        // 	for( auto x : ttt )
        // 	{
        // 		cout<<x.first;
        // 	}
        // 	cout<<endl;
        // };

      
        // auto print = [&]( )->void
        // {
        // 	print_(first_map);
        // 	print_(second_map);
        // 	print_(both_map);
        // 	cout<<endl;
        // };

        int res = 0 ;
        res = max( res , (int)both_map.size() );

        // print();

        int lim = f[1];

        for( int i = 1 ; i < lim ; i++ )
        {
        	int loose_first = i ;
        	int gain_first = lim+i ;

        	int loose_second = lim+i ;
        	int gain_second = i ;


        	// fop first_map 

        	// how many ends at i 
        	auto ends_at_i = end_boundry[loose_first];

        	for( auto x : ends_at_i )
        	{
        		first_map[x]--;
        		if( first_map[x] == 0 )
        		{
        			both_map.erase(x);
        			first_map.erase(x);
        		}
        	}

        	auto start_at_i = start_boundry[gain_first];

        	for( auto x : ends_at_i )
        	{
        		first_map[x]++;
        		if( first_map[x] == 1 )
        		{
        			both_map[x]++;
        		}
        	}


        	// for second_map 

        	ends_at_i = end_boundry[loose_second];

        	for( auto x : ends_at_i )
        	{
        		second_map[x]--;
        		if( second_map[x] == 0 )
        		{
        			both_map.erase(x);
        			second_map.erase(x);
        		}
        	}

        	start_at_i = start_boundry[gain_second];

        	for( auto x : start_at_i )
        	{
        		second_map[x]++;
        		if( second_map[x] == 1 )
        		{
        			both_map.erase(x);
        		}
        	}

        	res = max( res , (int)both_map.size() );
        }

        cout<<res<<endl;

    };
    

int test = 1 ;
cin>>test;
while(test--)
solve();
return 0;
}   
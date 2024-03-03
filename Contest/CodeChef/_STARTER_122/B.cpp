/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define all(x) begin(x) , end(x) 
// #define mask(i) (1LL << (i))
// #define vi vector<int>
// #define vvi vector<vi>
// const int mod = pow(10,9)+7 ;
// const int MAX = pow(10,5)+1 ;
// const int dx[8] = { 1 , -1 , 0 , 0 , 1 , 1 , -1 , -1 } ;
// const int dy[8] = { 0 , 0 , 1 , -1 , 1 , -1 , 1 , -1 } ;
// int mod_pow( int a , int b )
// {
//     if( a == 0 || a == 1 ) return a ;
//     if( b == 0 )return 1 ;
//     int ha = mod_pow( a , b/2 ); ha *= ha; ha %= mod ; if( b&1 ) ha *= a ;
//     return ha%mod ;
// }
// int inverse( int a )
// {
//     return mod_pow(a,mod-2);
// }
// vector<int> factorial( int N = MAX )
// {
//     vector<int>f(N,1);
//     for( int i = 2 ; i < N ; i++ )f[i] = (i*f[i-1])%mod;
//     return f ;
// }
// #define oo (int)pow(2L,60)
// #define arr array<int,3> 
// #define ar array<int,2>

/********** GO DOWN ***********/

/* 
   If the genius trains just as hard.... 
   what chance do I have to beat him? 
*/


class prefix_sum{
	int N ;
	vector<int>T ;

public:
	prefix_sum( const vector<int>&A ){
		N = A.size();
		T.resize(N+1,0);

		for( int i = 0 ; i < N ; i++ )
			T[i+1] = T[i] + A[i];
	}

	int range( int a , int b )
	{
		return T[b+1] - T[a];
	}
};

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    auto solve = [&]()->void
    {
        int N ;
        cin>>N ;
        
        vector<int>k(N);
        vector<int>w(N);

        for( auto &x : w )
        	cin>>x ;

        for( auto &x : k )
        	cin>>x ;


       
        int l =  1 ;
        int h =  pow(10LL,16);



        for( int i = 0 ; i < N ; i++ )
        	k.push_back(k[i]);

        for( int i = 0 ; i < N ; i++ )
        	w.push_back(w[i]);
       

     auto ok = [&]( int m )-> bool{

            int L = N ;

            for( int i = 0 ; i < N ; i++ )
            {
                int f = m ;
                int j = i ;
                for( ; j <= i+L-1 ; j++ )
                {
                    if( f < w[j] )
                        break;

                    f = w[j] + max( 0LL , f - k[j] );
                }

                if( j > i+L-1 )
                    return 1 ;
            }

            return 0 ;
        };


        
        while( l < h )
        {
            int m = (l+h)>>1 ;
            if(ok(m))
                h = m-1;
            else
                l = m+1;
        }


        for( int m = l-2 ; m <= l+2 ; m++ )
        {
            if( m >= 1 && ok(m) )
            {
                cout<<m<<endl;
                return ;
            }
        }
        cout<<l<<endl;
    };
    

        
    int test = 1 ;
    cin>>test;
    while(test--)
    solve();
    
    return 0;
}






























int dx[4] = { 1 , -1 , 0 , 0 };
int dy[4] = { 0 , 0 , 1 , -1 };

class Solution {

    int f = 0 ;

    void rec( vector<vector<char>>&A , int i , int j , string &S , int k , vector<vector<int>>&vis )
    {
        int M = A.size() ;
        int N = A[0].size();
        int L = S.size();

        if( i < 0 || i >= M || j < 0 || j >= N || k >= L || A[i][j] != S[k] || f )
        return ;


        if( k == L-1 )
        {
            f = 1 ;
            return ;
        }

        for( int p = 0 ; !f && p < 4 ; p++ )
        {
            int a = i + dx[p] ;
            int b = j + dy[p] ;

            
            if(vis[a][b] == 0 && !f)
            {
                
                rec( A , a , b , S , k+1 , vis );
                vis[a][b] = 0 ;
            }
        }


    }

    bool ok( vector< vector<char>>& A , int i , int j , string &S  )
    {
        int M = A.size();
        int N = A[0].size();
        vector< vector<int> > vis(M , vector<int>(N,0));
        f = 0 ;

        vis[i][j] = 1;
        rec(A , i , j , S , 0, vis );
        vis[i][j] = 0;
        return f ;
    }


public:
    bool exist(vector<vector<char>>& A , string S ) {
        int M = A.size();
        int N = A[0].size();


        for( int i = 0 ; i < M ; i++ )
        for( int j = 0 ; j < N ; j++ )
        {
            if(ok( A , i , j , S ))
            return 1 ;
        }
        return 0 ;
    }
};
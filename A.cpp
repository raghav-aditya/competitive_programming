/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) begin(x) , end(x) 
#define on(i) (1LL << (i))
#define mask(i) (on(i)-1LL)
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
























    string task( string A )
    {
        for( auto &x : A )
        {
            if( x == '-' )
                x = ' ';
        }

        stringstream ss(A);

        string x ;
        string res ;

        while( ss>>x ){

            reverse( x.begin() , x.end() );
            res += x ;
        }

        res.pop_back();
        reverse(res.begin() , res.end());
        return res;
    }





    vector< vector<string> > f( vector< vector< string > > &A )
    {

        vector< vector<string >  > B ;

        for( auto x : A )
        {

            string a = x[0];
            string b = x[1];
            string c = x[2];
            string d = x[3];
            string e ;

            if( c == "ERROR" || c == "CRITICAL" ){

                e = task(a); // 01 01 2023 -> 

                B.push_back({
                    e , b , c , d , a 
                });
            }
        }
        sort( B.begin() , B.end());
        vector< vector< string > > res ;

        for( auto &x : B )
        {

            string a = x[0];
            string b = x[1];
            string c = x[2];
            string d = x[3];
            string e = x[4];

            cout<<e<<" "<<b<<" "<<c<<" "<<d<<endl;
            res.push_back({ e , b , c , d });
        }

        return res ;

    }














int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector< vector< string > > A =
    {
        { "26-10-2020" , "04:21" , "ERROR" , "failed" },
        { "26-10-2020" , "15:03" , "ERROR" , "failed" },
        { "26-10-2020" , "08:59" , "ERROR" , "failed" }
    };


// 26-10-2020 04:21 ERROR failed
// 26-10-2020 15:03 ERROR failed
// 26-10-2020 08:59 ERROR failed

    // 01-01-2023
    // 10 10 3202 -> 2023 01 01 

    /// 2023 - 01 - 13 
    /// 2023 - 01 - 14

    f( A );
    return 0;
}
/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector<string> go( string A )
{
    sort( A.begin() , A.end() );
    vector<string> res ;
    res.push_back(A);
    while(next_permutation( A.begin() , A.end() ))
    {
        res.push_back(A);
    }

    return res;
}

void solve( int N ){


    int limit = log10(N);



    vector<int>t;
    for( int i = 1 ; i <= 9 ; i++ )
        t.push_back(i);

    vector<string> res ;

    for( int bit = 1 ; bit < pow(2,9) - 1 ; bit++ )
    {
        string A ; 
        for( int i = 0 ; i < 9 ; i++ )
        {
            if( bit&(1<<i) )
            {
                int cnt = t[i];
                char d = cnt + '0' ;
                while(cnt--)
                    A.push_back(d);
            }
        }

        if( abs( limit - (int)A.size() ) > 1 )continue ; // speed up
        auto half = go(A);

        for( auto x : half )
            res.push_back(x);

    }

    vector<int>A ; // numbers 
    for( auto x : res )
        A.push_back(stoll(x));

    sort( A.begin() , A.end() );
    cout<<*lower_bound( A.begin() , A.end() , N)<<endl;

    return ;
}

int32_t main() {

  solve(10101);

return 0;
}   
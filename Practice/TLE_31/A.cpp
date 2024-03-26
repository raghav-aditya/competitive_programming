/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void
    {
        int N ;
        cin>>N ;
        vector<int>A(N);

        for( auto &x : A )cin>>x ;
        sort( A.begin() , A.end() ) ;

        int res = 0 ;

        for( int s = 0 ; s <= 2*N ; s++ )
        {
           int cnt = 0 ;
           unordered_map< int , int >mp ;

            for( int i = 0 ; i < N ; i++ )
            {
                int x = A[i];
                int y = s-x ;

                if( mp.find(y) == mp.end() )
                {
                    mp[x]++;
                }
                else
                {
                    cnt++;
                    mp[y]--;
                    if( mp[y] == 0 )
                        mp.erase(y);
                }

            }

            res = max( res , cnt );
        }
        cout<<res<<endl;
    };
    solve();
    return 0;
}
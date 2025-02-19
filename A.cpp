/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/
#include <bits/stdc++.h>
using namespace std;


int32_t main() {

    int M , N ;
    cin>>M>>N ;
    vector<vector<int>>A(M,vector<int>(N,0));

    for( auto &x : A )
    for( auto &i : x )
        cin>>i ;


    int T ;
    cin>>T ;


    int i = 0 ;
    int j = N-1 ;

    while( i >= 0 && j >= 0 && i < M && j < N )
    {
        int curr = A[i][j];
        
        if( curr == T )
        {
            cout<<" found val "<<endl;
            cout<<i<<" "<<j<<endl;
            return 0 ;
        }
        else if ( curr < T )
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    cout<<" Not Found "<<endl;


return 0;
}   
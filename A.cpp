/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/
#include <bits/stdc++.h>
using namespace std;


int countSubsetsWithOR(vector<int>&A, int k ) {
   
        int N = A.size();
        int t[N+1][k+1];

        memset( t , 0 , sizeof t );
        for( int i = 0 ; i <= N ; i++ )
            t[i][0] = 1;

        for( int i = 1 ; i <= N ; i++ )
        for( int j = 1 ; j <= k ; j++ )
        {
            int v = A[i-1];

            t[i][j] += t[i-1][j];

            for( int s = j ; s != 0 ; s = (s-1)&j )
            {
                if( (s != j) && (s|v) == j )
                    t[i][j] += t[i-1][s];
            }
        }
        return t[N][k];
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int K = 1;
    cout << "Number of subsets with OR K: " << countSubsetsWithOR(arr, K) << endl;
    return 0;
}

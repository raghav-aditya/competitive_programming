/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/
#include <bits/stdc++.h>
using namespace std;

#define on(i) (1LL << (i))

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void{
    
        int N , Q ;
        cin>>N>>Q ;
        int L = 30;
        int T[N][L];
        for( int i = 0 ; i < N ; i++ )
        {
            int x ; cin>>x ;
            x--;
            T[i][0] = x ;
        }        
        
        for( int i = 1 ; i < L ; i++ )
        for( int u = 0 ; u < N ; u++ )    
        {
            int next = T[u][i-1];
            T[u][i] = T[next][i-1];
        }

        while(Q--)
        {
            int u , k ;
            cin>>u>>k ;
            u--;
            
            while(k)
            {
                int a = k&-k;
                k -= a ;
                a = log2(a);
                u = T[u][a];
            }

            cout<<u+1<<endl;
        }
    };
    

int test = 1 ;
while(test--)
solve();
return 0;
}   
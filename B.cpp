/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>



/********** GO DOWN ***********/

/* 
   If the genius trains just as hard.... 
   what chance do I have to beat him? 
*/

vvi g ;
vvi t ;
int k ;
 
void dfs( int u , int p = -2 )
{
    t[u][0] = p ;
 
    for( int i = 1 ; i < k ; i++ )
    {
        int up = t[u][i-1];
        if(up == -2)
            break;
        t[u][i] = t[up][i-1];
    }
 
    for( auto v : g[u] )
    {
        if( v == p )continue ;
        dfs( v , u );
    }
}
 
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void{
            int N , Q ;
            cin>>N>>Q ;
 
            k = log2(N)+1 ;
            g.resize(N);
            t.resize(N,vector<int>(k,-2));
 
            for( int i = 1 ; i < N ; i++ )
            {
                int x ; cin>>x ; x--;
                g[i].push_back(x);
                g[x].push_back(i);
            }
 
            dfs(0);
 
            while(Q--)
            {
                int x , p ;
                cin>>x>>p ; x-- ;
 
                for( int i = k-1 ; i >= 0 ; i-- )
                {
                    if(p>=(1<<i)){
                        x = t[x][i];
                        p -= (1<<i);
                        if( x== -2)
                            break;
                    }
                }
 
                cout<<x+1<<endl;
            }
 
    };
    
 
int test = 1 ;
while(test--)
solve();
return 0;
}
#include <bits/stdc++.h>
using namespace std ;


#define ar array<int,2>
#define arr array<int,3>

class Solution {
public:
    int findCheapestPrice(int N , vector<vector<int>>& E , int st , int en , int k) {
         vector< ar > g[N];
         for( auto x : E )
         {
             int a = x[0] ;
             int b = x[1] ;
             int w = x[2] ;

             g[a].push_back({ b , w });
         }

         vector< int > d( N , INT_MAX );
         d[st] = 0 ;
         queue< ar > q ;
         q.push({ st , 0 });
         int lv = 0 ;

         while( q.size() )
         {
             int sz = q.size();

             if( lv > k )
             break ;

             while(sz--)
             {
                 auto beg = q.front() ; q.pop(); 

                 int u = beg[0];
                 int cost = beg[1];

                 for( auto next : g[u] )
                 {
                     int v = next[0];
                     int w = next[1];

                     if( cost+w < d[v] )
                     {
                         d[v] = cost+w ;
                         q.push({ v , d[v] });
                     }
                 }
             }
             lv++;
         }
         return d[en] == INT_MAX ? -1 : d[en] ;
    }
};
/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve( string B , int N ){

         vector<int>A( N , 0 );
         iota( A.begin() , A.end() , 1 );
         
         int i = 0 ;
         int j = 0 ;
         
         while( j < B.size() )
         {
             if( B[j] == 'D' )
             {
                 while( j < B.size() && B[j] == 'D' )
                 {
                     j++;
                 }
                 
                 reverse( A.begin() + i , A.begin() + j+1  );
                 j = j+1;
             }
            
             j++;
             i = j ;
         }
         
         for( auto x : A  )
            cout<<x<<" ";
         cout<<endl;
}

int32_t main() {

  solve("ID" , 3 );

return 0;
}   
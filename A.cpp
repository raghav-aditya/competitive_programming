/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/



/*


You are designing the algorithm for a mechanical lock that has 4 knobs, each numbered from 0 to 9.
 Each knob can be rotated up or down by one step at a time (with wrap-around, i.e., 9 → 0 and 0 → 9).
You start from an initial configuration (e.g., "0000") and must reach a target configuration (e.g., "1254").
However, there are certain deadlock states (forbidden combinations).
 If you reach any of those, the lock jams and can’t move further through that configuration.
You must determine the minimum number of moves required to reach the target configuration without ever passing through a deadlock.
 If it’s impossible, return -1.
Example
initial = "0000"
target = "0002"
deadlocks = ["0001", "0101", "0102", "1212", "2002"]

Output:
Minimum moves: 4

0000 → 0010 → 0011 → 0012 → 0002

                    if(delta = 1 )
  10^N ----> (state1)---> (state2) ---->

  1ms

  a   b   [c]  d 



      
a---------------------------------------------b




*/


#include <bits/stdc++.h>
using namespace std;
#define int long long 

int L = 4 ;

int solve( string A , string B , vector<string> D ){


    if( A == B )
      return 0 ;

    unordered_set< string > vis( D.begin() , D.end() );
    queue< string >Q ;

    Q.push( A );
    vis.insert( A );


    int lv = 0 ; 


    while( Q.size() )
    {
        int sz = Q.size() ;

        while(sz--)
        {
            string beg = Q.front() ; Q.pop();

            if( beg == B )
              return lv ;


            auto orig = beg ;


            vector< string > posible ;

            for( int i = 0 ; i < beg.size() ; i++ )
            {

                  int v = beg[i]-'0';

                  int a = (v+1)%10 ;
                  int b = (10 + (v-1)%10)%10 ; 


                  auto f = beg ;
                  auto s = beg ;

                  f[i] = a + '0';
                  s[i] = b + '0';


                  posible.push_back(f);
                  posible.push_back(s);
            }



            for( auto next : posible )
            {
                if( vis.count(next) )
                  continue;

                vis.insert(next);

                Q.push(next);
            }


        }

        lv++;
    }






  return -1 ;
}

int32_t main() {

  string st = "0000";
  string end = "0002";
  vector< string > deadlocks = { "0001", "0101", "0102", "1212", "2002" };

  cout<<solve( st , end , deadlocks )<<endl;

  cout<<solve( "0000", "1234" , { "1000","9000","0100","0900","0010","0090","0001","0009" })<<endl;


  cout<<solve( "0000", "0009" , {} )<<endl;


return 0;
}   
/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){

    vector<int>A(12,0); 
    iota( A.begin() , A.end() , 1 );

    rotate( A.begin() , A.begin()+2 , A.end() );
    for( auto x : A )
      cout<<x<<",";

    cout<<endl;

}

int32_t main() {

  solve();

return 0;
}    


/*
  
  Prateek Downstream wala task, 
  Is week dev complete krk QA me move krdenge,
  on track for this task

 [a,b] [c,d]

 |a-c| + |b-d|

 -> a - c + b - d ->  a+b - ( c+d )
 -> a - c - b + d ->  a-c - ( c-d )

*/





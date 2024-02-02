#include <bits/stdc++.h>
using namespace std;


#include <ext/rope> //header with rope
using namespace __gnu_cxx;

int main()
{

    rope <int> v;
    for( int i = 1 ; i <= 10 ; i++ )
    v.push_back(i);
    
    for( auto x : v )
    cout<<x<<" ";
    cout<<endl;
    rope<int> a = v.substr( 0 , 3 );
    rope<int> b = v.substr( 5 , 3 );
    
    v.replace( 0 , 3 , b );
    v.replace( 5 , 3 , a );
    
    for( auto x : v )
    {
        cout<<x<<" ";
    }

    return 0;
}
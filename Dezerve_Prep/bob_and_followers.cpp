#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N; 
    long long k;
    cin >> N >> k;
    
    vector<int>A(N);
    for( auto &x : A )cin>>x ;

    int ans = 0;
    for( auto x : A )if( x == k )ans++;

    int res = 0 ;
    int off = 0 ;

    unordered_map< int , int > mp ;

    for( auto x : A )
    {
        if( x == k ){
            off--;
        }
        else
        {
            int lc = 0 ;
            if( mp.find(x) != mp.end() )
                lc = mp[x]+off;

            int mx = max( lc , 0 ) +  1 ;
            mp[x] = mx - off ;

            res = max( res , mx );
        }
    }

    cout<<ans+res<<endl;
    return 0;
}

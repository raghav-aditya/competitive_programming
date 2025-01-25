/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

#define int long long
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define all(x) begin(x) , end(x) 
#define on(i) (1LL << (i))
#define mask(i) (on(i)-1LL)
#define vi vector<int>
#define vvi vector<vi>
const int mod = pow(10,9)+7 ;
const int MAX = pow(10,5)+1 ;
const int dx[8] = { 1 , -1 , 0 , 0 , 1 , 1 , -1 , -1 } ;
const int dy[8] = { 0 , 0 , 1 , -1 , 1 , -1 , 1 , -1 } ;
int mod_pow( int a , int b , int md = mod )
{
    if( a == 0 || a == 1 ) return a ;
    if( b == 0 )return 1 ;
    int ha = mod_pow( a , b/2 ); ha *= ha; ha %= md ; if( b&1 ) ha *= a ;
    return ha%md ;
}
int inverse( int a )
{
    return mod_pow(a,mod-2);
}
vector<int>factorial_ ; 
vector<int> factorial( int N = MAX )
{
    vector<int>f(N,1);
    for( int i = 2 ; i < N ; i++ )f[i] = (i*f[i-1])%mod;
    return f ;
}
void init_factorial(){ if(factorial_.size()==0)factorial_ = factorial(); }
#define oo (int)pow(2L,60)
#define arr array<int,3> 
#define ar array<int,2>

int nCr( int N , int R )
{
    if(factorial_.size()==0) factorial_ = factorial();
    int res = factorial_[N]; res *= inverse( factorial_[R] );  
    res = (res%mod+mod)%mod; res *= inverse( factorial_[N-R] ); 
    res = (res%mod+mod)%mod; return res ;
}


/********** GO DOWN ***********/

/* 
   If the genius trains just as hard.... 
   what chance do I have to beat him? 
*/













long subproblem(int m, vector<vector<int>> &adj, int node, int parent, vector<int> &mpc, long &total) {
    const long mod = 1e9 + 7;
    int numChildren = adj[node].size();
    if (parent != -1) numChildren--;
    
    if (numChildren > m-2) return -1;
    if (numChildren == 0) return 0;
    
    total *= mpc[numChildren];
    total %= mod;
    
    for (int child : adj[node]) {
        if (child == parent) continue;
        int ret = subproblem(m, adj, child, node, mpc, total);
        if (ret == -1) return -1;
    }
    return 0;
}

int buildingMonuments(int m, int n, vector<int> &from, vector<int> &to) {
    const long mod = 1e9 + 7;
    
    // calculating (m-2) p c
    vector<int> mpc (m+1, 0);
    long mprod = m-2;
    for (int ii = 1; ii <= m-2; ++ii) {
        mpc[ii] = mprod;
        mprod *= (m-2-ii);
        mprod %= mod;
    }
    
    // create adj list
    vector<vector<int>> adj (n+1, vector<int>());
    for (int ii = 0; ii < from.size(); ++ii) {
        adj[from[ii]].push_back(to[ii]);
        adj[to[ii]].push_back(from[ii]);
    }
    
    // pick 1st node as a root and traverse down.
    int root = 1;
    long numPossible = m; // m way to set root
    int numRootChildren = adj[root].size();
    if (numRootChildren > m-1) return 0; //not possible
    
    // add (m-1) p numRootChildren
    long mproot = m-1;
    for (int ii = 1; ii < numRootChildren; ++ii) {
        mproot *= (m-1-ii);
        mproot %= mod;
    }
    numPossible *= mproot;
    numPossible %= mod;
    
    for (int child : adj[root]) {
        int ret = subproblem(m, adj, child, root, mpc, numPossible);
        if (ret == -1) return 0;
    }
    return numPossible;
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>from = { 1  } ;
    vector<int>to = { 2  };
    int m = 3 ; 

return 0;
}   


/*


solution 1 based index and neat and clean solution


int solve(int n, const vector<pair<int, int>>& edges, int m) {
    vector<vector<int>> graph(n + 1);
    
    // Building the graph
    for (const auto& edge : edges) {
        int u = edge.first, v = edge.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Sorting adjacency lists
    for (int i = 0; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    vector<int> counts(n + 1, 0);

    // Counting
    for (int i = 1; i <= n; ++i) {
        for (int j : graph[i]) {
            if (j < i) {
                counts[i] += upper_bound(graph[j].begin(), graph[j].end(), i) - graph[j].begin();
            }
        }
    }

    // Calculating the result
    long long ans = 1;
    const int mod = 1000000007;

    for (int i = 1; i <= n; ++i) {
        ans = (ans * (m - counts[i])) % mod;
    }

    return ans;
}

*/


// 1 - M 
// 2 - M-1 
// 3 - M-2 
// 4 - M-2

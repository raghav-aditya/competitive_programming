#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Read input: first n (number of people) then K (Bob's money)
    int n; 
    long long K;
    cin >> n >> K;
    
    vector<long long> A(n);
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    
    // Count how many people already have money equal to K.
    long long baseline = 0;
    for (int i = 0; i < n; i++){
        if(A[i] == K)
            baseline++;
    }
    
    // dp[v] will store a value so that the "actual" running sum for candidate v is dp[v] + off.
    unordered_map<long long, long long> dp; 
    long long off = 0;            // global offset (cumulative contribution from K's)
    long long global_best = 0;    // best "actual" value (maximum net gain from some operation)
    
    // Process the array in one pass.
    for (int i = 0; i < n; i++){
        if(A[i] == K){
            // For a K, every candidate's running sum decreases by 1.
            off--;
        } else {
            // Only the candidate equal to A[i] gets a contribution.
            long long v = A[i];
            long long old_actual = 0;
            if(dp.find(v) != dp.end()){
                old_actual = dp[v] + off;
            }
            // Kadane-style update:
            long long new_actual = max(old_actual, 0LL) + 1;
            dp[v] = new_actual - off;  // store adjusted value so that actual = dp[v] + off.
            global_best = max(global_best, new_actual);
        }
        // (Indices with neither K nor a candidate value don't need an update;
        //  their contribution is 0 so they merely "bridge" segments.)
    }
    
    // Final answer: add the net gain from our best operation (if any) to the baseline.
    long long ans = baseline + global_best;
    cout << ans << "\n";
    
    return 0;
}

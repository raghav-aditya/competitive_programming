#include <bits/stdc++.h>

using namespace std;

#define ar array<int,2>

int func(vector<int>& A) {
    vector<int> dp(A.size(), 0);
    stack< ar > st ;
    st.push({ INT_MAX , 0});

    for (int i = 1; i < (int)A.size(); ++i) {
        while (st.top()[0] <= A[i]) {
            st.pop();
        }
        dp[i] = dp[st.top()[1]] + A[i] * abs(i-st.top()[1]);
        st.push({A[i], i});
    }
    return dp.back();
}

int main() {
    vector<int> arr = {3,7,10,12,8,10};
    cout << func(arr) << endl; // Output the result
    return 0;
}

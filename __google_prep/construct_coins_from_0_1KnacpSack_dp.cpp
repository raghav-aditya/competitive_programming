
#include <bits/stdc++.h>
using namespace std;

vector<int> constructOriginalArray(vector<int> &dp) 
{
vector<int> originalArr;
int i, j, n = dp.size();

    for(i=1;i<n;i++) 
    {
        if (dp[i] == 1) 
        {
            for(j=n-1;j>=i;j--)
            dp[j] = dp[j] - dp[j-i];
            originalArr.push_back(i);
        }
    }
    return originalArr;
}

int main() {
// Write C++ code here
vector<int> dp = {1, 0, 1, 0, 1, 1, 2, 1, 2, 1, 3};
vector<int> originalArr = constructOriginalArray(dp);
for(int num: originalArr) {
cout<<num<<" ";
}
return 0;
}
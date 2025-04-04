https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/description/


#include <bits/stdc++.h>
using namespace std ;

    int minIncrements(int n, vector<int>& A) {
        int res = 0;
        for (int i = n / 2 - 1; i >= 0; --i) {
            int l = i * 2 + 1, r = i * 2 + 2;
            res += abs(A[l] - A[r]);
            A[i] += max(A[l], A[r]);
        }
        return res;
    }

int main(){
	return 0;
}
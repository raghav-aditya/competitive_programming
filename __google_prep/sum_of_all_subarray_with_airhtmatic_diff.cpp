#include<bits/stdc++.h>
using namespace std;

int task( vector<int>&A , int d )
{
    int N = A.size();
    int res = 0 ;

    for( int i = 0 ; i < N ; i++ )
    {
        int j = i+1 ;
        while( j < N && j < N && A[j] - A[j-1] == d )
            j++;
        j--;

        int lc = 0 ;
        int L = j-i+1 ;
        int a = L;
        int b = 1 ;

        for( int k = i ; k <= j ; k++ ){
            lc += a*b*A[k];
            a--;
            b++;
        }
        res += lc ;
        i = j ;
    }
    return res;
}

int solve( vector<int>&A )
{
    int sum = accumulate( A.begin() , A.end() , 0LL );
    return task(A,1) + task(A,-1) - sum ;
}

int main(){
    //int sum = 0;
    // vector<int>nums = {7,4,5,6,5};
    vector<int>nums = {1,2,1};
    cout<<solve(nums)<<endl;   
}


/*

A good arithmetic sequence is an arithmetic sequence with a common difference of either 1 or -1.

For example, [4, 5, 6] is a good arithmetic sequence. So is [6, 5, 4], [10, 9], or [-3, -2, -1]. But, [1, 2, 1] (no common difference) or [3, 7] (common difference is 4) is NOT.
Implied, any sequence that has only one element is a good arithmetic sequence.

For example, [4] is a good arithmetic sequence.
Given an integer array nums, return the sum of the sums of each subarray that is a good arithmetic sequence.

Example:

Given nums = [7, 4, 5, 6, 5]. Each of the following subarrays is a good arithmetic sequence:

[7], [4], [5], [6], [5],
[4, 5], [5, 6], [6, 5],
[4, 5, 6]
The sums of these subarrays are:

7, 4, 5, 6, 5,
4 + 5 = 9, 5 + 6 = 11, 6 + 5 = 11,
4 + 5 + 6 = 15
Thus, the answer is the sum of all the sums above, which is:

7 + 4 + 5 + 6 + 5 + 9 + 11 + 11 + 15 = 73.

[5 6 7 8 9]
[6 7 8]

*/
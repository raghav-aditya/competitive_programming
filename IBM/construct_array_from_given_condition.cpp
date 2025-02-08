/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/
#include <bits/stdc++.h>
using namespace std;


/*

Give an array of integers of length n, arr,
and two integers l and r, find another array brr, such that:


l <= brr[i] <= r
brr[i] - arr[i] < brr [i+1] - arr[i+1], for every i less than n - 1
brr[i] <= brr[i+1] for every i less than n - 1
Among all such arrays, return the lexicographically smallest one.
If there is not an array that satisfies the conditions,
then return an array with the single element -1.


Example
arr = [1, 2, 1, 2], l = 1, r = 10


The array [1, 3, 3, 5] satisfies given conditions.


Each elemtent belongs in the range [1, 10]
Construct an array crr where crr[i] = brr[i] - arr[i], crr = [0, 1, 2, 3]
The array brr is non-decreasing
brr[i] - arr[i] for each element [0, 1, 2, 3]
1 - 1 = 0
3 - 2 = 1
3 - 1 = 2
5 - 2 = 3


Note that all brr[i] >= arr[i] as well.
There is not a lexicographically smaller array than [1, 3, 3, 5]
that satisfies the conditions.


*/



// solution:

/*

Greedy


(1) brr[0] = L
(2) brr[i + 1] - brr[i] >= max(arr[i + 1] - arr[i] + 1, 0)


So brr[i + 1] = brr[i] + max(arr[i + 1] - arr[i] + 1, 0)


Construct the array brr using a simple loop, if we reach one brr[x] > R, there is no solution.

*/


int32_t main() {
  
return 0;
}   
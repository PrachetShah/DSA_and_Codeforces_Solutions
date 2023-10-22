/*
Given an array of integers of size N, for all, i's [1, N], the task is to find the minimum subarray sum in the subarray [i, N].

Input:
1. The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
2. The first line of each test case contains a single integer N.
3. The second line contains N space-separated positive integers represents array.

Output: For each test case, print N space-separated integers

Constraints:
1. 1 <= T <= 10
2. 1 <= N <= 100000
3. -10000 <= arr[i] <= 10000

Example:
Input:
2
3
3 -1 -2
5
5 -3 -2 9 4

Output:
-3 -3 -2
-5 -5 -2 4 4

Explanation:
Test case 1:

1. i = 1, subarray is [3, -1, -2], all possible subarrays are [3], [-1], [-2], [3, -1], [-1, -2], [3, -1, -2]. Minnimum sum is -3 [-1, -2].
2. i = 2, subarray is [-1, -2], all possible subarrays are [-1], [-2], [-1, -2]. Minnimum sum is -3 [-1, -2].
3. i = 3, subarray is [-2], all possible subarrays are [-2]. Minnimum sum is -2[-2].


*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> nums(n);
	    for(int i=0; i<n; i++){
	        cin >> nums[i];
	    }
	    
	    vector<int> ans;
	    for(int j=0; j<n; j++){
    	    int minn=nums[j], min_so_far=0;
            
    	    for(int i=j; i<n; i++){
    	        min_so_far = min(nums[i], min_so_far+nums[i]);
    	        if(minn > min_so_far){
    	            minn = min_so_far;
    	        }
    	    }
    	    cout << minn << " ";
	    }
	    cout << "\n";
	}
	
	return 0;
}
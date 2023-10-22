/*
Convert an array to reduced form
EasyAccuracy: 54.74%Submissions: 44K+Points: 2
Given an array with N distinct elements, convert the given array to a reduced form where all elements are in range from 0 to N-1. The order of elements is same, i.e., 0 is placed in place of smallest element, 1 is placed for second smallest element, and N-1 is placed for the largest element.

Note: You don't have to return anything. You just have to change the given array.

Example 1:

Input:
N = 3
Arr[] = {10, 40, 20}
Output: 0 2 1
Explanation: 10 is the least element so it
is replaced by 0. 40 is the largest
element so it is replaced by 3-1 = 2. And
20 is the 2nd smallest element so it is
replaced by 1.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) {
	    // code here
	    unordered_map<int, int> unorderedMap;
	    
	    int temp[n];
	    memcpy(temp, arr, n*sizeof(int));
	    
	    sort(temp, temp+n);
	    
	    for(int i=0; i<n; i++){
	        unorderedMap[temp[i]] = i;
	    }
	    
	    for(int i=0; i<n; i++){
	        arr[i] = unorderedMap[arr[i]];
	    }
	    
	}

};
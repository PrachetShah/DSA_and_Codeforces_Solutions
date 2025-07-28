#include<bits/stdc++.h>

using namespace std;

// Follow up over Median of 2 Sorted Arrays
class Solution {
public:
    double KthElementOfSortedArrays(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n2 > n1){
            return KthElementOfSortedArrays(nums2, nums1, k);
        }
        int n = n1 + n2;

        // low, and high will be diff because of greater k, and max values of high
        int low = max(k-n2, 0);
        int high = min(k, n1);

        // parition here would be at k, since we dont want median
        int left = k;
        while(low <= high){
            int mid1 = (low+high)/2;
            int mid2 = left-mid1;

            int r1 = INT_MAX;
            int r2 = INT_MAX;
            int l1 = INT_MIN;
            int l2 = INT_MIN;

            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];
            if(mid1 - 1 >= 0) l1 = nums1[mid1-1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2-1];

            if(l1 <= r2 && l2 <= r1){
                // valid partition
                return max(l1, l2);
            }else if(l1 > r2){
                high = mid1 - 1;
            }else{
                low = mid1 + 1;
            }
        }
        return 0.0;
    }
};
#include<bits/stdc++.h>

using namespace std;

// if mid == even index, then check for Next Index
// if mid == odd index, then check for prev Index
// multiple conditions avoided using check with XOR operation
// 3 -> 3^1 = (11^1) = 2
// 6 -> 6^1 = (110^1) = 111 = 7

// in order to check for left half,
// 1st instance -> even index
// 2nd instance -> odd index, i need to check on the left if 1st instance of that number is there or not

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-2;
        while(low <= high){
            int mid = (low+high) >> 1;
            if(nums[mid] == nums[mid^1]){
                low = mid+1;
            }else{
                high = mid-1;
            }
            // Condition without XOR Operation
            //we are in the left:
            // if ((mid % 2 == 1 && arr[mid] == arr[mid - 1])
            //         || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            //     //eliminate the left half:
            //     low = mid + 1;
            // }
            // //we are in the right:
            // else {
            //     //eliminate the right half:
            //     high = mid - 1;
            // }
        }
        return nums[low];
    }
};
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        // OPTIMAL -> Doing both merhe and count in single function 
        int mergeAndCount(int low, int high, int mid, vector<int> &nums){
            int start = low;
            int end = mid+1;
            int cnt=0;
            for (int i = low; i <= mid; i++) {
                while (end <= high && (long)nums[i] > (long)2*nums[end]) end++;
                cnt += end - (mid + 1);
            }
            end =mid+1;
            vector<int> temp;
            while(start<=mid && end<=high){
                if(nums[start] < nums[end]){
                    temp.push_back(nums[start++]);
                }else{
                    temp.push_back(nums[end++]);
                }
            }
            while(start<=mid){
                temp.push_back(nums[start++]);
            }
            while(end<=high){
                temp.push_back(nums[end++]);
            }
            for(int i=low; i<=high; i++){
                nums[i] = temp[i-low];
            }
            return cnt;
        }
        
        // Semi Optimal -> Merging in One func and counting pairs in another
        void merge(int low, int high, int mid, vector<int> &nums){
            int start = low;
            int end = mid+1;
            vector<int> temp;
            while(start<=mid && end<=high){
                if(nums[start] < nums[end]){
                    temp.push_back(nums[start++]);
                }else{
                    temp.push_back(nums[end++]);
                }
            }
            while(start<=mid){
                temp.push_back(nums[start++]);
            }
            while(end<=high){
                temp.push_back(nums[end++]);
            }
            for(int i=low; i<=high; i++){
                nums[i] = temp[i-low];
            }
        }
        int countPairs(int low, int high, int mid, vector<int> &nums){
            int cnt = 0;
            int right = mid+1;
            for(int i=low; i<=mid; i++){
                while(right<=high && (long)nums[i] > (long)2*nums[right]){
                    right++;
                }
                cnt += right-(mid+1);
            }
            return cnt;
        }

        // Core Function, for both OPTIMAL and SEMI-OPTIMAL
        int mergeSort(int low, int high, vector<int> &nums){
            int cnt = 0;
            if(low >= high){
                return cnt;
            }
            int mid = (low+high)/2;
            cnt += mergeSort(low, mid, nums);
            cnt += mergeSort(mid+1, high, nums);
            // cnt += countPairs(low, high, mid, nums);
            // merge(low, high, mid, nums);
            cnt += mergeAndCount(low, high, mid, nums);
            return cnt;
        }


        int reversePairs(vector<int>& nums) {
            return mergeSort(0, nums.size()-1, nums);
        }
    };

template <typename T> void print(vector<T> arr){
    cout << "{ ";
    for(auto num: arr){
        cout << num << " ";
    }
    cout << "} ";
}

int main(){
    cout << "CODE COMPILED" << endl;
    Solution classObj = Solution();
    
    vector<int> nums = {1,3,2,3,1};
    int ans = classObj.reversePairs(nums);
    cout << "Number of reverse pairs for: ";
    print(nums);
    cout << "are: " << ans;    
    
    return 0;
}
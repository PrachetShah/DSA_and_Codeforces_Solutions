#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canBloom(vector<int> &bloomDay, int day, int m, int k){
        int bouquets = 0;
        int flowers = 0;
        // sliding window to can bloom or not
        for(auto bloom: bloomDay){
            if(bloom <= day){
                flowers++;
                if(flowers == k){
                    bouquets++;
                    flowers = 0;
                    if(bouquets >= m) return true;
                }
            }else{
                flowers = 0;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1ll*m*k > bloomDay.size()){
            return -1;
        }

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while(low <= high){
            int mid = (low+high) >> 1;
            if(canBloom(bloomDay, mid, m, k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
};
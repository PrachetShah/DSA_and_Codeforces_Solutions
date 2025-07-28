#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int> &weights, int allowedDays, int allowedWeight){
        int currLoad = 0;
        int days = 1;
        for(auto wt: weights){
            currLoad += wt;
            if(currLoad > allowedWeight){
                days++;
                currLoad = wt;
            }
        }
        return days <= allowedDays;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = accumulate(weights.begin(), weights.end(), 0);
        int low = *max_element(weights.begin(), weights.end());
        int high = maxWeight;
        int ans = maxWeight;

        while(low <= high){
            int mid = (low + high) >> 1;
            if(check(weights, days, mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
};
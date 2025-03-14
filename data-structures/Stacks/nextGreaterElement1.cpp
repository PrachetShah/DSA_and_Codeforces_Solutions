#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;

        for(auto num: nums2){
            while(!st.empty() && num > st.top()){
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        vector<int> ans;
        for(auto num: nums1){
            int val = mp[num]==0 ? -1 : mp[num];
            ans.push_back(val);
        }
        return ans;
    }
};
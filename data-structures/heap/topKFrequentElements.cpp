#include<bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;


vector<int> topKFrequentElements(vector<int> arr, int k){

    auto cmp = [](pii a, pii b){
        return a.second < b.second;
    };
    priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
    
    unordered_map<int, int> freq;
    for(int num: arr){
        freq[num]++;
    }

    for(auto mp: freq){
        pq.push({mp.first, mp.second});
    }

    vector<int> ans;
    for(int i=0; i<k; i++){
        ans.push_back(pq.top().first);
        pq.pop();
    }

    for(int num: ans){
        cout << num << " ";
    }
    cout << "\n";

    return ans;
}

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    auto ans = topKFrequentElements(nums, 2);
}
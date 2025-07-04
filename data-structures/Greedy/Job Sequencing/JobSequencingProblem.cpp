// C++ program to solve job sequencing
// problem with maximu profit
#include <bits/stdc++.h>
using namespace std;

// Brute Force
// TC: O(N^2), SC: O(N)
vector<int> jobSequencingBrute(vector<int> &deadline, vector<int> &profit) {
    int n = deadline.size();
    int cnt = 0;
    int totalProfit = 0;
    
    
    vector<pair<int, int>> jobs;
    for(int i=0; i<n; i++){
        jobs.push_back({profit[i], deadline[i]});
    }
    
    // sort in ascending order
    sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());
    
    vector<int> slot(n, -1);
    
    for(int i=0; i<n; i++){
        int start = min(n, jobs[i].second) - 1;
        for(int j=start; j>=0; j--){
            if(slot[j] == -1){
                slot[j] = i;
                cnt++;
                totalProfit += jobs[i].first;
                break;
            }
        }
    }
    
    return {cnt, totalProfit};
}

// Optimal
// TC: O(nlogn) + O(n)
// SC: O(n)
vector<int> jobSequencingOptimal(vector<int> &deadline, vector<int> &profit){
    int n = deadline.size();
    int cnt = 0;
    int totalProfit = 0;

    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; i++) {
        jobs.push_back({deadline[i], profit[i]});
    }

    // sort the jobs based on deadline
    // in ascending order
    sort(jobs.begin(), jobs.end());

    // to maintain the scheduled jobs based on profit
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto job : jobs) {
        // if job can be scheduled within its deadline
        if (job.first > pq.size())
            pq.push(job.second);
        
        // Replace the job with the lowest profit
        else if (!pq.empty() && pq.top() < job.second) {
            pq.pop();
            pq.push(job.second);
        }
    }

    while(!pq.empty()){
        totalProfit += pq.top();
        pq.pop();
        cnt++;
    }
    return {cnt, totalProfit};
}

int main(){
    vector<int> deadline = {2, 1, 2, 1, 1};
    vector<int> profit = {100, 19, 27, 25, 15};
    vector<int> ans = jobSequencingBrute(deadline, profit);
    cout << ans[0] << " " << ans[1] << endl;
    ans = jobSequencingOptimal(deadline, profit);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
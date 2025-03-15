#include<bits/stdc++.h>

using namespace std;

int taskSchedulingPQ(vector<char> tasks, int n){
    // TC: O(n logk) -> O(n) since k is constant, SC: O(26)
    vector<int> freq(26, 0);
    for(auto task: tasks){
        freq[task-'A']++;
    }

    priority_queue<int> pq;
    for(auto f: freq){
        if(f>0){
            pq.push(f);
        }
    }

    int time = 0;
    while(!pq.empty()){
        int cycle = n+1;
        vector<int> store;
        int taskCount = 0;
        while(cycle-- && !pq.empty()){
            if(pq.top() > 0){
                store.push_back(pq.top()-1);
            }
            pq.pop();
            taskCount++;
        }

        for(int x: store){
            pq.push(x);
        }
        time += pq.empty() ? taskCount : n+1;
    }
    return time;
}

// Maths approach
/*
Calculate the frequency and maximum frequency for tasks
Count total number of tasks with maxFreq
Final Time: [(maxFreq-1)(n+1) + countTask] with max Freq
AAAABBBC
n = 2
A B C | A B _ | A B
Ans: MAX{ (3-1)(n+1) + 2 -> (8) , tasks.size() ]
*/

int main(){
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int ans = taskSchedulingPQ(tasks, 2);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    using pii = pair<int, int>;

    int maxMeetings(vector<int> &start, vector<int> &end){
        // Your code here
        vector<pii> schedules;
        for (int i = 0; i < end.size(); i++){
            schedules.push_back(make_pair(end[i], start[i]));
        }
        sort(schedules.begin(), schedules.end());

        int meetings = 1;
        int prev = schedules[0].first;

        for (int i = 1; i < end.size(); i++){
            if (schedules[i].second > prev){
                meetings++;
                prev = schedules[i].first;
            }
        }

        return meetings;
    }
};
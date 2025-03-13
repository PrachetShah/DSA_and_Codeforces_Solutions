#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> intervals){
	sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
		return a[0] < b[0];
	});
	vector<vector<int>> merged;
	vector<int> prev = intervals[0];
	for(int i=1; i<intervals.size(); i++) {
		if(intervals[i][0] <= prev[1]){
			prev[1] = intervals[i][1];
		}else{
			merged.push_back(prev);
			prev = intervals[i];
		}
	}
	merged.push_back(prev);
	return merged;
}

int main(){
    vector<vector<int>> intervals = {{1,3}, {4,8}, {6, 9}, {10, 12}, {11, 16}};
    vector<vector<int>> ans = mergeIntervals(intervals);
    for(auto a: ans){
        cout << "{ " << a[0] << " " << a[1] << " },\t";
    }
}
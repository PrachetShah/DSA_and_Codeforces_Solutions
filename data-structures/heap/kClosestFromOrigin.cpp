#include<bits/stdc++.h>

using namespace std;

// Using SORTING
static int sqDistance(vector<int> &point){
    return (point[0]*point[0]) + (point[1]*point[1]);
}

// ascending order comparator
static bool comparator(vector<int> &a, vector<int> &b){
    // less for ascending order
    return sqDistance(a) < sqDistance(b);
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // Approach using sorting
    sort(points.begin(), points.end(), comparator);

    vector<vector<int>> ans(points.begin(), points.begin()+k);
    return ans;
}

// -------------------------------------------------------------------------
using pivi = pair<int, vector<int>>;
// Heap Apporach
vector<vector<int>> kClosestHeap(vector<vector<int>>& points, int k) {
    // Max heap automatically checks the int of pair for comparing
    priority_queue< pivi > pq;
    
    for(int i=0; i<k; i++){
        int dis = sqDistance(points[i]);
        pq.push({dis, points[i]});
    }

    for(int i=k; i<points.size(); i++){
        int dis = sqDistance(points[i]);
        if(dis < pq.top().first){
            pq.pop();
            pq.push({dis, points[i]});
        }
    }

    vector<vector<int>> ans;
    for(int i=0; i<k; i++){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int main(){
    vector<vector<int>> points = {{1, 3}, {-2, 2}, 
                            {5, -1}, {3, 2}, {1, 1}};
    int k = 3;
    cout << "Original Array:\n";
    for (vector<int> point: points) {
        cout << "[" << point[0] << ", " << point[1] << "]\t";
    }


    vector<vector<int>> res = kClosest(points, k);
    cout << "\n\nK Closest from Origin with Sorting:\n";
    for (vector<int> point: res) {
        cout << "[" << point[0] << ", " << point[1] << "]\t";
    }
    
    vector<vector<int>> ress = kClosestHeap(points, k);
    cout << "\n\nK Closest from Origin with Heap Approach:\n";
    for (vector<int> point: ress) {
        cout << "[" << point[0] << ", " << point[1] << "]\t";
    }

    return 0;
}
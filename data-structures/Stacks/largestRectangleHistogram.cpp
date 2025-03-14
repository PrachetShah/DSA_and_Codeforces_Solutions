#include<bits/stdc++.h>

using namespace std;

int largestRectangleOptimal(vector<int> &heights){
    stack<int> s;
    int ans = 0;
    int n = heights.size();

    for(int i=0; i<n; i++){
        while(!s.empty() && heights[s.top()] > heights[i]){
            int temp = s.top();
            s.pop();
            int width = s.empty() ? i : i-s.top()-1;
            ans = max(ans, heights[temp]*width);
        }
        s.push(i);
    }

    while(!s.empty()){
        int temp = s.top();
        s.pop();
        int width = s.empty() ? n : n-s.top()-1;
        ans = max(ans, heights[temp]*width);
    }
    return ans;
}

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    cout << largestRectangleOptimal(heights);
}
#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int count(vector<int> &arr, int maxPages, int k){
        int students = 1;
        int totalPages = 0;
        for(auto page: arr){
            if(totalPages + page > maxPages){
                students++;
                totalPages = page;
            }else{
                totalPages += page;
            }
        }
        return students;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(arr.size() < k){
            return -1;
        }
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        while(low <= high){
            int mid = (low+high) >> 1;
            int cntStudents = count(arr, mid, k);
            if(cntStudents > k){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};
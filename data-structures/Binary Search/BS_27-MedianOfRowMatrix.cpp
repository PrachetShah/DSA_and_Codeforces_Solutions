#include<bits/stdc++.h>

using namespace std;

// TC: O(log2(10^9)*n*log2(m))
class Solution {
  private:
    int upperBound(vector<int> arr, int toSearch, int m){
        int ans = m;
        int low = 0;
        int high = arr.size()-1;
        
        while(low <= high){
            int mid = (high+low)/2;
            if(arr[mid] > toSearch){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
  
    int countSmallEqual(vector<vector<int>> &mat, int toSearch, int n, int m){
        int cnt = 0;
        for(int i=0; i<n; i++){
            cnt += upperBound(mat[i], toSearch, m);
        }
        return cnt;
    }
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int req = (n*m)/2;
        
        int low = INT_MAX;
        int high = INT_MIN;
        
        for(int i=0; i<n; i++){
            low = min(low, mat[i][0]); 
            high = max(high, mat[i][m-1]); 
        }
        
        while(low <= high){
            int mid = low + (high-low)/2;
            int smallEqual = countSmallEqual(mat, mid, n, m);
            if(smallEqual <= req){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};

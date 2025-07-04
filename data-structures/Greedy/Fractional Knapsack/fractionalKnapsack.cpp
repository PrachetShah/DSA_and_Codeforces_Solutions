#include<bits/stdc++.h>

using namespace std;

// Method 1
class Solution {
    public:
    
    // Custom Comparator, Comparison function to sort items based on value/weight ratio
    static bool compare(vector<int> &a, vector<int> &b){
        double a1 = (1.0*a[0])/a[1];
        double b1 = (1.0*b[0])/b[1];
        return a1 > b1;
    }
    
    // METHOD 1: Using Custom Comparator in C++
    double fractionalKnapsackUsingComparator(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        double ans = 0;
        int bag = capacity;
        vector<vector<int>> items(n, vector<int>(2));
        
        for(int i=0; i<val.size(); i++){
            items[i][0] = val[i];
            items[i][1] = wt[i];
        }
        
        // sort in ascending, using custom comparator compare has to be static when called from a class or global
        sort(items.begin(), items.end(), compare);
        
        for(int i=0; i<items.size(); i++){
            if(items[i][1] <= bag){
                bag -= items[i][1];
                ans += items[i][0];
            }else{
                ans += (double)(1.0*items[i][0]/items[i][1])*bag;
                // IMP: sack is full
                break;
            }
        }
        return ans;
    }

    // METHOD 2: Without Comparator, and directly using available comparator in C++
    double fractionalKnapsackGlobalCompare(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        double ans = 0;
        int bag = 0;
        vector<vector<double>> items;
        
        for(int i=0; i<val.size(); i++){
            items.push_back({(double)val[i]/wt[i], (double)wt[i], (double)val[i]});
        }
        
        // sort in ascending, using Inbuilt comparator for descending order
        sort(items.begin(), items.end(), greater<vector<double>>());
        
        for(auto item: items){
            if(item[1]+bag <= capacity){
                bag += item[1];
                ans += item[2];
            }else{
                int remain = capacity - bag;
                ans += (double)(1.0*item[0])*remain;
                // IMP: sack is full
                break;
            }
        }
        return ans;
    }
};


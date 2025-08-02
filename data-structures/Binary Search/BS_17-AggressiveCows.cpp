#include<bits/stdc++.h>

using namespace std;

/*
We want to find maximum of (minimum distance between stalls)
So Eg:
Stalls = [0 9 4 3 10 7]
It can be placed at any stalls, so we can sort the stalls to assign them to stalls in consecutive order

1. Sort(stalls.begin(), stalls.end())

Now,
Stalls = [0 3 4 7 9 10], cows = 4

Assume minDist = 1
So, 0 (3) 3 (1) 4 (3) 7 9 10
    c1    c2   c3    c4
with this config, max of min distances between allocated cows is (3,1,3) -> 1

Assume minDist = 2
So, 0 (3) 3   4    7 (2) 9  10
    c1   c2  (4)  c3    c4 
with this condif, we cannot assign cows in stalls 3&4 because distance b/w them is 1 and we need 2
so max of min distances between allocated cows is (3,4,2) -> 2

Assume minDist = 3
So, 0        3   4    7   9    10
    c1 (3)  c2  (4)  c3  (3)   c4 
with this condif, we cannot assign cows in stalls 3&4 because distance b/w them is 1 and we need 2
so max of min distances between allocated cows is (3,4,3) -> 3

Assume minDist = 4
So, 0   3   4    7   9    10
    c1 (4) c2  (5)  c3  
with this condif, we cannot assign cows in stalls because min distance of 4, we cannot assing all cows

So max of min distances is for Min Distance = 3

This can be done usiong Binary Search with minDist = 1 (can also be taken  min of stalls), and maxDist = max(stalls)-min(stalls)

Using Binary Search, because of polarity, when we increrase low = mid+1, for changing conditions, 
we get ans stored at high when loop breaks

Further Optimation for Range can be
    int low = 1;
    int high = stalls[n-1]-stalls[0];
*/

class Solution {
  public:
    bool count(vector<int> stalls, int minDist, int k){
        int dist = stalls[0];
        int cows = 1;
        for(int i=0; i<stalls.size(); i++){
            if(stalls[i]-dist >= minDist){
                cows++;
                dist = stalls[i];
                if(cows == k){
                    return true;
                }
            }
        }
        return (cows==k);
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.end());
        
        int n = stalls.size();
        int low = 0;
        int high = stalls[n-1];
        
        while(low <= high){
            int mid = (high+low) >> 1;
            if(count(stalls, mid, k)){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return high;
        
    }
};

int main(){
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    using pii = pair<int, int>;
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int> &arr, vector<int> &dep){
        // Optimal
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int ans = 1;
        int count = 1;
        int i = 1, j = 0;
        while (i < n && j < n){
            if (arr[i] <= dep[j]) // one more platform needed
            {
                count++;
                i++;
            }
            else // one platform can be reduced
            {
                count--;
                j++;
            }
            ans = max(ans, count); // updating the value with the current maximum
        }
        return ans;
    }
};

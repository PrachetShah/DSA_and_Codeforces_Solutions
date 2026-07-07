#include<bits/stdc++.h>

using namespace std;

// Using Recursion
int f(int index, vector<int> jumps){
    if (index == 0){
        return 0;
    }
    int left = f(index-1, jumps) + abs(jumps[index] - jumps[index-1]);
    int right = INT_MAX;
    if(index > 1){
        right = f(index-2, jumps) + abs(jumps[index] - jumps[index-2]);
    }
    return min(left, right);
}

int frogJumpRec(vector<int> jumps){
    return f(jumps.size()-1, jumps);
}

// Memoization
int fM(int index, vector<int> jumps, vector<int> dp){
    if (index == 0){
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }
    int left = fM(index-1, jumps, dp) + abs(jumps[index] - jumps[index-1]);
    int right = INT_MAX;
    if(index > 1){
        right = fM(index-2, jumps, dp) + abs(jumps[index] - jumps[index-2]);
    }
    return dp[index] = min(left, right);
}

int frogJumpMem(vector<int> jumps){
    vector<int> dp(jumps.size(), -1);
    dp[0] = 0;
    return fM(jumps.size()-1, jumps, dp);
}

// DP
int frogJumpDp(vector<int> jumps){
    vector<int> dp(jumps.size(), 0);
    dp[0] = 0;

    for(int index=1; index<jumps.size(); index++){
        int left = dp[index-1] + abs(jumps[index] - jumps[index-1]);
        int right = INT_MAX;
        if(index > 1){
            right = dp[index-2] + abs(jumps[index] - jumps[index-2]);
        }
        dp[index] = min(left, right);
    }
    return dp[jumps.size()-1];
}

// Space Optimized DP
int frogJumpSp(vector<int> jumps){
    int prev2 = 0;
    int prev1 = 0;

    for(int index=1; index<jumps.size(); index++){
        int left = prev1 + abs(jumps[index] - jumps[index-1]);
        int right = INT_MAX;
        if(index > 1){
            right = prev2 + abs(jumps[index] - jumps[index-2]);
        }
        int curr = min(left, right);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main(){
    vector<int> jumps = {30, 10, 60, 10, 60, 50};
    cout << "Minimum energy required to reach the last stone: " << endl;
    cout << "Minimum energy required (Recursion): \t" << frogJumpRec(jumps) << endl;
    cout << "Minimum energy required (Memoization): \t" << frogJumpMem(jumps) << endl;
    cout << "Minimum energy required (Tabulation): \t" << frogJumpDp(jumps) << endl;
    cout << "Minimum energy required (SO DP): \t" << frogJumpSp(jumps) << endl;
    return 0;
}
/*
Coin Change II
Return the total number of combinations that make up that amount.
Infinite Supply Problem
Finding num of ways so, dont add 1 to pick which is used to find minimum num of coins since we need total, 
not the total in one min-max situation
This is a variation of the Coin Change Problem where we need to find the number of ways to make a certain amount using given denominations.
This problem can be solved using dynamic programming techniques similar to the Unbounded Knapsack Problem.
*/
#include<bits/stdc++.h>

using namespace std;


// Recursion
// TC: O(exponential)
// SC: O(N)
int f(int index, int target, vector<int> &coins){
    if(index == 0){
        return target%coins[0] == 0;
    }

    int notPick = 0 + f(index-1, target, coins);
    int pick = 0;
    if(target >= coins[index]){
        pick = f(index, target-coins[index], coins);
    }
    return pick + notPick;
}

int coinChange2Rec(int target, vector<int> coins){
    int n = coins.size();
    return f(n-1, target, coins);
}

// Memoization
// TC: O(N*T)
// SC: O(N*T) + O(N)
int fm(int index, int target, vector<int> &coins, vector<vector<int>> &dp){
    if(index == 0){
        return target%coins[0] == 0;
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }
    int notPick = 0 + f(index-1, target, coins);
    int pick = 0;
    if(target >= coins[index]){
        pick = f(index, target-coins[index], coins);
    }
    return dp[index][target] = pick + notPick;
}

int coinChange2Mem(int target, vector<int> coins){
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    return fm(n-1, target, coins, dp);
}

// Tabulation
// TC: O(N*T)
// SC: O(N*T)
int coinChange2Tab(int target, vector<int> coins){
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(target+1, 0));

    for(int T=0; T<=target; T++){
        dp[0][T] = T%coins[0] == 0;
    }

    for(int i=1; i<n; i++){
        for(int T=0; T<=target; T++){
            int notPick = dp[i-1][T];
            int pick = 0;
            if(T >= coins[i]){
                pick = dp[i][T-coins[i]];
            }
            dp[i][T] = pick + notPick;
        }
    }

    return dp[n-1][target];
}

// Space Optimisation
// TC: O(N*T)
// SC: O(T)
int coinChange2SP(int target, vector<int> coins){
    int n = coins.size();
    vector<long long> prev(target+1, 0);

    for(int T=0; T<=target; T++){
        prev[T] = T%coins[0] == 0;
    }

    for(int i=1; i<n; i++){
        vector<long long> curr(target+1, 0);
        for(int T=0; T<=target; T++){
            int notPick = prev[T];
            int pick = 0;
            if(T >= coins[i]){
                pick = curr[T-coins[i]];
            }
            curr[T] = pick + notPick;
        }
        prev = curr;
    }

    return prev[target];
}

// Most Optimised, one array answer
int coinChange2MOP(int target, vector<int> coins){
    vector<unsigned long long> dp(target + 1, 0); 
    dp[0] = 1;
    
    for (int c : coins) {
        for (int a = c; a <= target; a++) {
            dp[a] += dp[a - c];
        }
    }
    
    return dp[target];
}

int main(){
    vector<int> coins = {1,2,5};
    int target = 5;
    cout << "REC:\t" << coinChange2Rec(target, coins) << endl;
    cout << "MEM:\t" << coinChange2Mem(target, coins) << endl;
    cout << "TAB:\t" << coinChange2Tab(target, coins) << endl;
    cout << "SP:\t" << coinChange2SP(target, coins) << endl;
    cout << "MOP:\t" << coinChange2MOP(target, coins) << endl;
}
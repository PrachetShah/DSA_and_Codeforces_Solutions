// Greedy approach fails because of not uniformity
// this is like knapsack where we mfound max value, here we will have min count
// infinite supply of coins, so either keep taking the coin, or dont take

#include<bits/stdc++.h>

using namespace std;

/*Recursion*/
// TC: More than O(2^n) since can be repeated -> exponential
// SC: more than O(n), since standing at same space, can goto max of O(TARGET)
int f(int index, int target, vector<int> coins){
    if(index==0){
        if(target%coins[0] == 0){
            return target/coins[0];
        }else{
            return 1e9;
        }
    }
    // take, so count+1
    int take = INT_MAX;
    if(coins[index] <= target){
        // infinite supply, so dont change index
        take = 1 + f(index, target-coins[index], coins);
    }
    // not take, so count will not increase
    int notTake = 0 + f(index-1, target, coins);
    return min(take, notTake);
}
int minCoinsRec(int target, vector<int> coins){
    int n = coins.size();
    int ans = f(n-1, target, coins);
    return ans >= 1e9 ? -1 : ans;
}

/*Memoization*/
// TC: O(N*T)
// SC: O(N*T) + O(T)
int fm(int index, int target, vector<int> coins, vector<vector<int>> &dp){
    if(index==0){
        if(target%coins[0] == 0){
            return target/coins[0];
        }else{
            return 1e9;
        }
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }
    // take, so count+1
    int take = INT_MAX;
    if(coins[index] <= target){
        // infinite supply, so dont change index
        take = 1 + fm(index, target-coins[index], coins, dp);
    }
    // not take, so count will not increase
    int notTake = 0 + fm(index-1, target, coins, dp);
    return dp[index][target] = min(take, notTake);
}
int minCoinsMem(int target, vector<int> coins){
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    int ans = fm(n-1, target, coins, dp);
    return ans >= 1e9 ? -1 : ans;
}

/*Tabulation*/
// Target: 0->T
// TC: O(N*T)
// SC: O(N*T)
int minCoinsTab(int target, vector<int> coins){
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(target+1, 0));

    for(int T=0; T<=target; T++){
        if(T % coins[0] == 0){
            dp[0][T] = T/coins[0];
        }else{
            dp[0][T] = 1e9;
        }
    }

    for(int index=1; index<n; index++){
        for(int T=0; T<=target; T++){
            // take, so count+1
            int take = INT_MAX;
            if(coins[index] <= T){
            // infinite supply, so dont change index
                take = 1 + dp[index][T-coins[index]];
            }
            // not take, so count will not increase
            int notTake = 0 + dp[index-1][T];
            dp[index][T] = min(take, notTake);
        }
    }

    return dp[n-1][target] >= 1e9 ? -1 : dp[n-1][target];
}

/*Space Optimisation*/
// TC: O(N*T)
// SC: O(T)
int minCoinsSP(int target, vector<int> coins){
    int n = coins.size();
    vector<int> prev(target+1, 0);

    for(int T=0; T<=target; T++){
        if(T % coins[0] == 0){
            prev[T] = T/coins[0];
        }else{
            prev[T] = 1e9;
        }
    }

    for(int index=1; index<n; index++){
        vector<int> curr(target+1, 0);
        for(int T=0; T<=target; T++){
            // take, so count+1
            int take = INT_MAX;
            if(coins[index] <= T){
            // infinite supply, so dont change index
                take = 1 + curr[T-coins[index]];
            }
            // not take, so count will not increase
            int notTake = 0 + prev[T];
            curr[T] = min(take, notTake);
        }
        prev = curr;
    }

    return prev[target] >= 1e9 ? -1 : prev[target];
}

int main(){
    vector<int> coins = {1,3, 2};
    int target = 7;

    cout << "REC\t" << minCoinsRec(target, coins) << endl;
    cout << "MEM\t" << minCoinsMem(target, coins) << endl;
    cout << "TAB\t" << minCoinsTab(target, coins) << endl;
    cout << "SP\t" << minCoinsSP(target, coins) << endl;

    return 0;
}
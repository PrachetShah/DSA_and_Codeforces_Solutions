/*
* Unbounded Knapsack Problem
* This problem is similar to the 0-1 Knapsack Problem, but in this case, we can take an item multiple times.
* The goal is to maximize the total value of items that can fit in the knapsack without exceeding its weight capacity.
*/

#include<bits/stdc++.h>

using namespace std;

// Recursion Top Down
// TC: O(exponential)
// SC: O(N)
int f(int index, int bagWeight, vector<int> weight, vector<int> value){
    if(index==0){
        return (bagWeight >= weight[index]) ? value[0] : 0;
    }
    int notPick = f(index-1, bagWeight, weight, value);
    int pick = INT_MIN;
    if(bagWeight >= weight[index]){
        pick = value[index] + f(index, bagWeight - weight[index], weight, value);
    }
    return max(pick, notPick);
}

int unboundedKnapsackRec(int bagWeight, vector<int> weight, vector<int> value){
    int n = weight.size();
    return f(n-1, bagWeight, weight, value);
}

// Memoization
// TC: O(N*W)
// SC: O(N*W) + O(N)
int fm(int index, int bagWeight, vector<int> weight, vector<int> value, vector<vector<int>> &dp){
    if(index == 0){
        return (bagWeight >= weight[index]) ? value[0] : 0;
    }
    if(dp[index][bagWeight] != -1) return dp[index][bagWeight];
    
    int notPick = fm(index-1, bagWeight, weight, value, dp);
    int pick = INT_MIN;
    if(bagWeight >= weight[index]){
        pick = value[index] + fm(index, bagWeight - weight[index], weight, value, dp);
    }
    return dp[index][bagWeight] = max(pick, notPick);
}

int unboundedKnapsackMem(int bagWeight, vector<int> weight, vector<int> value){
    int n = weight.size();
    vector<vector<int>> dp(n, vector<int>(bagWeight + 1, -1));
    return fm(n-1, bagWeight, weight, value, dp);
}

// Tabulation, Bottom Up
// TC: O(N*W)
// SC: O(N*W)
int unboundedKnapsackTab(int bagWeight, vector<int> weight, vector<int> value){
    int n = weight.size();

    vector<vector<int>> dp(n, vector<int>(bagWeight+1, 0));

    for(int i=weight[0]; i<=bagWeight; i++){
        dp[0][i] = value[0];
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<=bagWeight; j++){
            int notPick = dp[i-1][j];
            int pick = INT_MIN;
            if( j >= weight[i]){
                pick = value[i] + dp[i][j-weight[i]];
            }
            dp[i][j] = max(pick, notPick);
        }
    }

    return dp[n-1][bagWeight];
}

// Space Optimisation
// TC: O(N*W)
// SC: O(W)
int unboundedKnapsackSP(int bagWeight, vector<int> weight, vector<int> value){
    int n = weight.size();

    vector<int> prev(bagWeight+1, 0);

    for(int i=0; i<=bagWeight; i++){
        prev[i] = ((int)i/weight[0])*value[0];
    }

    for(int i=1; i<n; i++){
        vector<int> curr(bagWeight+1, 0);
        for(int j=0; j<=bagWeight; j++){
            int notPick = prev[j];
            int pick = INT_MIN;
            if( j >= weight[i]){
                pick = value[i] + curr[j-weight[i]];
            }
            curr[j] = max(pick, notPick);
        }
        prev = curr;
    }

    return prev[bagWeight];
}

// Space Optimisation with One Array
// TC: O(N*W)
// SC: O(W)
/*
Why Forward Order(inverse compared to bounded 0-1 knapsack):
In the unbounded knapsack problem, you can pick an item multiple times. Therefore, when calculating the 
maximum value for a given weight, you need to consider all possible combinations of using the current item 
zero times, one time, two times, and so on, up to the maximum number of times it can fit within the current weight. 
Looping forward (from 0 to bagWeight) allows you to consider these possibilities by accumulating values as you 
go through the weights.
*/
int unboundedKnapsackMOP(int bagWeight, vector<int> weight, vector<int> value){
    int n = weight.size();

    vector<int> prev(bagWeight+1, 0);

    for(int i=0; i<=bagWeight; i++){
        prev[i] = ((int)i/weight[0])*value[0];
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<=bagWeight; j++){
            int notPick = prev[j];
            int pick = INT_MIN;
            if( j >= weight[i]){
                pick = value[i] + prev[j-weight[i]];
            }
            prev[j] = max(pick, notPick);
        }
    }

    return prev[bagWeight];
}


int main(){
    vector<int> weight = {2, 4, 6};
    vector<int> value = {5, 11, 13};
    int bagWeight = 10;
    
    cout << "REC\t" << unboundedKnapsackRec(bagWeight, weight, value) << endl;
    cout << "MEM\t" << unboundedKnapsackMem(bagWeight, weight, value) << endl;
    cout << "TAB\t" << unboundedKnapsackTab(bagWeight, weight, value) << endl;
    cout << "SP\t" << unboundedKnapsackSP(bagWeight, weight, value) << endl;
    cout << "MOP\t" << unboundedKnapsackMOP(bagWeight, weight, value) << endl;
    
    return 0;
}
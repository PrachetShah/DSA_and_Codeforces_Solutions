#include<bits/stdc++.h>

using namespace std;

// Type Names
using ll = long long;
using vll = vector <ll>;
using pll = pair <ll, ll>;
using vpl = vector <pll>;

const ll INF = ll(1E18)+16;
const int MOD = 1e9+7;

/*Recursion*/
// TC: O(2^n) -> Exponential
// SC: O(N)
int f(int index, int bagWeight, vector<int> weight, vector<int> value){
    if(index == 0){
        return (bagWeight >= weight[index]) ? value[0] : 0;
    }
    // take
    int take = INT_MIN;
    if(bagWeight >= weight[index]){
        take = value[index] + f(index-1, bagWeight - weight[index], weight, value);
    }
    // notTake
    int notTake = 0 + f(index-1, bagWeight, weight, value);
    return max(take, notTake);
}
int zeroOne_KnapSackRec(int bagWeight, vector<int> weight, vector<int> value){
    int n = weight.size();
    return f(n-1, bagWeight, weight, value);
}

/*Memoization*/
// TC: O(N*W)
// SC: O(N*W) + O(N)
int fm(int index, int bagWeight, vector<int> weight, vector<int> value, vector<vector<int>> &dp){
    if(index == 0){
        return (bagWeight >= weight[index]) ? value[0] : 0;
    }
    if(dp[index][bagWeight] != -1){
        return dp[index][bagWeight];
    }
    // take 
    int take = INT_MIN;
    if(bagWeight >= weight[index]){
        take = value[index] + f(index-1, bagWeight - weight[index], weight, value);
    }
    // notTake
    int notTake = 0 + f(index-1, bagWeight, weight, value);
    dp[index][bagWeight] = max(notTake, take);
    return dp[index][bagWeight];
}
int zeroOne_KnapSackMem(int bagWeight, vector<int> weight, vector<int> value){
    int n = weight.size();
    vector<vector<int>> dp(n, vector<int>(bagWeight+1, -1));
    return fm(n-1, bagWeight, weight, value, dp);
}


/*Tabulation*/
// TC: O(N*W)
// SC: O(N*W)
int zeroOne_KnapsackTab(int bagWeight, vector<int> weight, vector<int> value){
    int n = weight.size();
    vector<vector<int>> dp(n, vector<int>(bagWeight+1, 0));

    // base case
    for(int W=weight[0]; W<=bagWeight; W++){
        dp[0][W] = value[0];
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<=bagWeight; j++){
            // take
            int take = INT_MIN;
            if(j >= weight[i]){
                take = value[i] + dp[i-1][j-weight[i]];
            }
            // notTake
            int notTake = dp[i-1][j];
            dp[i][j] = max(take, notTake);
        }
    }

    return dp[n-1][bagWeight];
}

/*Space Optimised*/
// TC: O(N*W)
// SC: O(W)
int zeroOne_KnapsackSP(int bagWeight, vector<int> weight, vector<int> value){
    int n = weight.size();
    vector<int> prev(bagWeight+1, 0);

    // base case
    for(int W=weight[0]; W<=bagWeight; W++){
        prev[W] = value[0];
    }

    for(int i=1; i<n; i++){
        vector<int> curr(bagWeight+1, 0);
        for(int j=0; j<=bagWeight; j++){
            // take
            int take = INT_MIN;
            if(j >= weight[i]){
                take = value[i] + prev[j-weight[i]];
            }
            // notTake
            int notTake = prev[j];
            curr[j] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[bagWeight];
}

/*Space Optimsed Further*/
// TC: O(N*W)
// SC: O(W)
// There is no need of right elements if started from bagWeight, and went to 0, 
// hence we only need to have 1 array needed to store the computations for it
// So need for Curr, as prev only stores all the required weights since it only requires [j] and [j-weight[i]]
int zeroOne_KnapsackSPF(int bagWeight, vector<int> weight, vector<int> value){
    int n = weight.size();
    vector<int> prev(bagWeight+1, 0);

    // base case
    for(int W=weight[0]; W<=bagWeight; W++){
        prev[W] = value[0];
    }

    for(int i=1; i<n; i++){
        for(int j=bagWeight; j>=0; j--){
            // take
            int take = INT_MIN;
            if(j >= weight[i]){
                take = value[i] + prev[j-weight[i]];
            }
            // notTake
            int notTake = prev[j];
            prev[j] = max(take, notTake);
        }
    }

    return prev[bagWeight];
}


int main(){
    vector<int> weight = {3,2,5};
    vector<int> value = {30, 40 ,60};
    int bagWeight = 6;
    cout << "0-1 Knapsack Problem:\n";
    cout << "---------------\n";
    cout << "REC:\t" << zeroOne_KnapSackRec(bagWeight, weight, value) << endl;
    cout << "MEM:\t" << zeroOne_KnapSackMem(bagWeight, weight, value) << endl;
    cout << "TAB:\t" << zeroOne_KnapsackTab(bagWeight, weight, value) << endl;
    cout << "SP:\t" << zeroOne_KnapsackSP(bagWeight, weight, value) << endl;
    cout << "SPF:\t" << zeroOne_KnapsackSPF(bagWeight, weight, value) << endl;
    cout << "---------------\n";
}
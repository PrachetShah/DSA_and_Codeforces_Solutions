#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(a==0){
        return b;
    }
    return gcd(b%a, a);
}

// RECURSION
// TC: O(N^2)
int recur(int index, int curr_gcd, vector<int> arr){
    if(index == arr.size()){
        return curr_gcd == 1 ? 1 : 0;
    }
    // pick and not pick
    int pick = recur(index+1, gcd(arr[index], curr_gcd), arr);
    int notPick = recur(index+1, curr_gcd, arr);

    return pick+notPick;
}

int subsequencesWithGCDOneRec(vector<int> arr){
    int total = 0;
    for(int i=0; i<arr.size(); i++){
        total += recur(i, arr[i], arr);
    }
    return total;
}

// Memoization
// TC: O(n * max(A))
int recurMem(int index, int curr_gcd, vector<int> arr, vector<vector<int>> &dp){
    if(index == arr.size()){
        return curr_gcd == 1 ? 1 : 0;
    }
    if(dp[index][curr_gcd]!=-1){
        return dp[index][curr_gcd];
    }
    // pick and not pick
    int pick = recur(index+1, gcd(arr[index], curr_gcd), arr);
    int notPick = recur(index+1, curr_gcd, arr);

    return dp[index][curr_gcd]=pick+notPick;
}

int subsequencesWithGCDOneMem(vector<int> arr){
    int total = 0;
    vector<vector<int>> dp(arr.size(), vector<int>(*max_element(arr.begin(), arr.end(), -1)));
    for(int i=0; i<arr.size(); i++){
        total += recurMem(i, arr[i], arr, dp);
    }
    return total;
}

int main(){
    vector<int> arr = {3, 4, 8, 16};
    int ans = subsequencesWithGCDOneRec(arr);
    return 0;
}
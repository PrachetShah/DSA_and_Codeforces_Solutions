#include<bits/stdc++.h>

using namespace std;

// Space Optimised DP Approach
int uniquePaths(int m, int n){
    int col = m;
    int row = n;

    vector<int> prevRow(row, 0);

    for(int i=0; i<=col-1; i++){
        vector<int> temp(row, 0);
        for(int j=0; j<=row-1; j++){
            if(i==0 && j==0){
                temp[j] = 1;
            }else{
                temp[j] = prevRow[j] + temp[j-1];
            }
        }
        prevRow = temp;
    }
    for(int i=0; i<row; i++){
        cout << prevRow[i] << " ";
    }
    cout << endl;
    return prevRow[row-1];
}

int main(){
    int m = 3;
    int n = 7;
    int ans = uniquePaths(m, n);
    cout << ans;
}
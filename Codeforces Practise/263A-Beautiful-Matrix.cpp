#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<vector<int>> matrix(5, vector<int> (5, 0));

    int ans;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 1){
                // You can either print ans here
                ans = abs(j-2) + abs(i-2);
                cout << ans;
                break;
            }
        }
    }
    // Or here
    // cout << ans << endl;

    // Printing Vector
    // for(int i=0; i<5; i++){
    //     for(int j=0; j<5; j++){
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
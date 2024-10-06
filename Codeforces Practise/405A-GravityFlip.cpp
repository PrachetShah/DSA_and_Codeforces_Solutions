#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> cols(n);

    for(int i=0; i<n; i++){
        cin >> cols[i];
    }

    if(n==1){
        cout << cols[0];
    }else{
        // int end = n-1;

        // for(int i = end; i>=1; i--){
        //     int start = i-1;
        //     while(start >= 0){
        //         if(cols[start] > cols[i]){
        //             cols[start]--;
        //             cols[i]++;
        //         }else{
        //             start--;
        //         }
        //     }
        // }
        // for(int i=0; i<cols.size(); i++){
        //     cout << cols[i] << " ";
        // }
        sort(cols.begin(), cols.end());
        for(int i=0; i<cols.size(); i++){
            cout << cols[i] << " ";
        }
    }

    
    return 0;
}
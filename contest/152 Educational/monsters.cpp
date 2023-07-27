#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> health(n);
        vector<int> indices(n);

        for(int i=0; i<n; i++){
            cin >> health[i];
        }
        int order = 1;
        bool flag = true;
        while(flag){
            if(order > n){
                break;
            }
            int ele = health[0], index=0;
            // find max
            for(int i=0; i<n; i++){
                if(health[i] > ele){
                    ele = health[i];
                    index = i;
                }
            }
            // cout << "MAX: " << ele << " " << index << endl;
            health[index] -= k;
            if(health[index] <= 0){
                // cout << "CONDITION CALLED, ORDER: " << order << endl; 
                indices[index] = order;
                order++;
            }
            // cout << "ARRAY AFTER DEDUCTION: " << endl;
            // for(int i=0; i<n; i++){
            //     cout << health[i] << " ";
            // }
            // cout << endl;
        }
        for(int i=0; i<n; i++){
            cout << indices[i] << " ";
        }
        cout << endl;
    }
}
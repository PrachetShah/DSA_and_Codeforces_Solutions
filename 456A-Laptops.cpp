#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    // Taking Input of Prices and Quality of Laptops
    vector<pair<int, int>> laptops(n);
    for(int i=0; i<n; i++){
        cin >> laptops[i].first >> laptops[i].second;
    }

    // Sorting the Laptops based on Prices
    sort(laptops.begin(), laptops.end());
    bool flag = true;

    // Checking for Condition if quality[i] > quality[i+1] after sorting
    for(int i=0; i<n-1; i++){
        if(laptops[i].second > laptops[i+1].second){
            cout << "Happy Alex" << endl;
            flag = false;
            break;
        }
    }

    if(flag){
        cout << "Poor Alex" << endl;
    }
    return 0;
}
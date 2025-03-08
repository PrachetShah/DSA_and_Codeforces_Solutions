#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> badges;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        badges.push_back(temp);
    }
    int cost = 0;
    int tot = (n)*(n+1)/2;
    int sumArr = accumulate(badges.begin(), badges.end(), 0);
    cout << tot - sumArr;
}
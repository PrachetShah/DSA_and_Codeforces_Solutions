#include<bits/stdc++.h>

using namespace std;

int main(){
    int k;
    cin >> k;

    vector<int> a(12);
    for(int i=0; i<12; i++){
        cin >> a[i];
    }

    int months = 0;
    int val = 0;
    sort(a.begin(), a.end(), greater<int>());
    
    for(int i=0; i<12; i++){
        if(val >= k){
            cout << i << endl;
            break;
        }
        val += a[i];
        months++;
    }
    // cout << "VAL: " << val << endl;
    if(val < k){
        cout << -1 << endl;
    }else if(months == 12){
        cout << 12 << endl;
    }
    // cout << "Months: " << months;

    return 0;
}
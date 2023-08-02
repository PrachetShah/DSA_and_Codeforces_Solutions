#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long int n;
        cin >> n;
        vector<int> students(n);
        for(int i=0; i<n; i++){
            cin >> students[i];
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            if(students[i] == i+1){
                ans++;
            }
        }
        if(ans%2 == 0)
            cout << ans/2 << endl;
        else
            cout << ans/2 + 1 << endl;
    }
    return 0;
}
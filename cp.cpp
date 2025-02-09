#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int t;
    cin >> t;

    while(t--){
        int n,m;
        cin >> n >> m;
        vector<int> arr;
        for(int i=0; i<n; i++){
            int val;
            cin >> val;
            arr.push_back(val);
        }
        bool done = false;
        for(int i=1; i<n; i++){
            if(arr[i] > m){
                cout << "NO" << endl;
                done = true;
                break;
            }
        }
        if(!done){
            cout << "YES" << endl;
        }
    }

    return 0;
}
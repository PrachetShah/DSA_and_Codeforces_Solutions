// GETTING Memory Limit Exceeded
#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n,m;
        cin >> n >> m;
        string binary;
        cin >> binary;

        int low, high;
        int ans = 0;
        unordered_set<string> store;
        for(int i=0; i<m; i++){
            cin >> low >> high;
            // cout << binary << " " << low << " " << high << endl;
            string temp = binary;
            sort(temp.begin()+low-1, temp.begin()+high);
            if(store.find(temp) == store.end()){
                store.insert(temp);
                ans++;
            }

            // cout << "STRING at " << i << " : " << temp << endl; 
        }
        cout << ans << endl;
    }

    return 0;
}
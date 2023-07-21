#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        vector<pair<int, int>> path(3);
        for(int i=0; i<3; i++){
            int x, y;
            cin >> x >> y;
            path[i] = make_pair(x, y);
            // cout << "CO: " << path[i].first << " " << path[i].second << endl;
        }
        int ans = 0;
        ans += (abs(path[0].first-path[1].first) + abs(path[0].second-path[1].second));
        ans += (abs(path[0].first-path[2].first) + abs(path[0].second-path[2].second));
        ans -= (abs(path[2].first-path[1].first) + abs(path[2].second-path[1].second));
        ans /= 2;
        ans += 1;
        cout << ans << endl;
    }

    // for(int i=0; i< path.size(); i++){
    //     cout << path[i].first << " " << path[i].second << endl;
    // }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int NinjaTraining(int n, vector< vector<int> > &points){
    vector<int> prevDay(4, 0);
    prevDay[0] = max(points[0][1], points[0][2]);
    prevDay[1] = max(points[0][0], points[0][2]);
    prevDay[2] = max(points[0][0], points[0][1]);
    prevDay[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int i=1; i<n; i++){
        vector<int> temp(4, -1);
        for(int last=0; last<4; last++){
            int maxi = INT_MIN;
            for(int task=0; task<3; task++){
                if(task != last){
                    temp[last] = max(points[i][task]+prevDay[task], temp[last]);
                }
            }
        }
        prevDay = temp;
    }
    return prevDay[3];
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        vector< vector<int> > grid(n, vector<int>(3, 0));
        cin >> n;
        for(int i=0; i<n; i++){
            for(int j=0; i<3; j++){
                int val;
                cin >> val;
                grid[i][j] = val;
            }
        }
        int maxPoints = NinjaTraining(n, grid);
        cout << "Max Points for Training by ninja are: " << maxPoints << endl;
    }

    return 0;
}
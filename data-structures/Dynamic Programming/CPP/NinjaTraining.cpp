#include <bits/stdc++.h>
using namespace std;

// Recursion Top Down
int recurSolve(int day, int last, int totalDays, vector<vector<int>> points){
    if(day==0){
        int maxi = 0;
        for(int i=0; i<totalDays; i++){
            if(i != last){
                int curr = points[day][i];
                maxi = max(maxi, curr);
            }
        }
        return maxi;
    }
    int maximum = 0;
    for(int i=0; i<totalDays; i++){
        if(i != last){
            int curr = points[day][i] + recurSolve(day-1, i, totalDays, points);
            maximum = max(maximum, curr);
        }
    }
    return maximum;
}

int NinjaTrainingRecur(int n, vector<vector<int>> points){
    return recurSolve(n-1, 3, 3, points);
}

// Memoixation
int memSolve(int day, int last, int totalDays, vector<vector<int>> points, vector<vector<int>> &dp){
    if(day==0){
        int maxi = 0;
        for(int i=0; i<totalDays; i++){
            if(i != last){
                int curr = points[day][i];
                maxi = max(maxi, curr);
            }
        }
        return maxi;
    }
    if(dp[day][last] != -1){
        return dp[day][last];
    }
    int maximum = 0;
    for(int i=0; i<totalDays; i++){
        if(i != last){
            int curr = points[day][i] + memSolve(day-1, i, totalDays, points, dp);
            maximum = max(maximum, curr);
        }
    }
    return dp[day][last] = maximum;
}

int NinjaTrainingMem(int n, vector<vector<int>> points){
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return memSolve(n-1, 3, 3, points, dp);
}

// Space Optimisation
int NinjaTrainingSP(int n, vector< vector<int> > &points){
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(3));
        for(int i=0; i<n; i++){
            for(int j=0; j<3; j++){
                int val;
                cin >> val;
                grid[i][j] = val;
            }
        }
        cout << "INPUT DONE" << endl;
        int maxPoints = NinjaTrainingSP(n, grid);
        int max2 = NinjaTrainingRecur(n, grid);
        int max3 = NinjaTrainingMem(n, grid);

        cout << "[RECU]\tMax Points for Training by ninja are: " << max2 << endl;
        cout << "[MEM]\tMax Points for Training by ninja are: " << max3 << endl;
        cout << "[SP]\tMax Points for Training by ninja are: " << maxPoints << endl;
    }

    return 0;
}
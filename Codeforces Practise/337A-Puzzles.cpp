#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    vector<int> puzzles(m);
    for(int i=0; i<m; i++){
        cin >> puzzles[i];
    }

    sort(puzzles.begin(), puzzles.end());

    int small = puzzles[n-1] - puzzles[0];
    int diff = puzzles[n-1] - puzzles[0];
    for(int i=0; i<m-n+1; i++){
        diff = puzzles[n-1+i] - puzzles[i];
        small = min(small, diff);
    }
    cout << small;
    return 0;
}
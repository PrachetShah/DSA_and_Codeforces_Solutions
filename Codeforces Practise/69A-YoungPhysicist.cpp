#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> forces(n, vector<int>(3, 0));

    int ans = 0;
    int x=0, y=0, z=0;
    for(int i=0; i<n; i++){
        cin >> forces[i][0] >> forces[i][1] >> forces[i][2];
        x += forces[i][0]; 
        y += forces[i][1]; 
        z += forces[i][2];
    }

    if(x == 0 && y==0 && z==0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
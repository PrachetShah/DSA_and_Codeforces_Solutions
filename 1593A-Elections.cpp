#include<bits/stdc++.h>

using namespace std;

int solveSingle(int best, int one, int two){
    return max(0, max(one, two)-best+1);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        cout << solveSingle(a, b, c) << ' ' << solveSingle(b, a, c) << ' ' << solveSingle(c, a, b) << endl;
    }
    return 0;
}
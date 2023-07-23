#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    string seq;
    cin >> seq;

    int zeros = count(seq.begin(), seq.end(), '0');
    int ones = count(seq.begin(), seq.end(), '1');
    
    int ans = n - 2*min(zeros, ones);
    cout << ans;
    return 0;   
}
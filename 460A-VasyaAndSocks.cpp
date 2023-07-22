#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int s;
    s = n + n/(m - 1);
    if (n%(m - 1) == 0)
        s -= 1;

    cout << s << endl;
    return 0;
}
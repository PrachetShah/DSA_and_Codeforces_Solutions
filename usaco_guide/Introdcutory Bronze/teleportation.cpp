#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

// the argument is the input filename without the extension
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void tc(){

}

int main() {
	setIO("teleport");

    int a,b,x,y;
    cin >> a >> b >> x >> y;

    int dist = abs(b-a);
    dist = min(dist, abs(a-x) + abs(b-y));
    dist = min(dist, abs(a-y) + abs(b-x));
    cout << dist;
}
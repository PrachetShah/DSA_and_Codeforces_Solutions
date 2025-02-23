#include <iostream>
#include <cstdio>
#include<vector>
using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}


int main() {
	setIO("paint");

	vector<bool> cover(100);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	for (int i = a; i < b; i++) { cover[i] = true; }
	for (int i = c; i < d; i++) { cover[i] = true; }

	int ans = 0;
	for (int i = 0; i < cover.size(); i++) { ans += cover[i]; }
	cout << ans << endl;
}
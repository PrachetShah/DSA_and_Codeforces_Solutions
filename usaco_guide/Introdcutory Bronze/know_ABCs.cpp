#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

// use it in bracket -> a%(MOD);
#define MOD 1000000007;

using ll = long long;
using vll = vector <ll>;
using ii = pair <ll, ll>;
using vii = vector <ii>;

// the argument is the input filename without the extension
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void tc(){
    vector<int> nums;
    int n;
    for(int i=0; i<7; i++){
        cin >> n;
        nums.push_back(n);
    }
    sort(nums.begin(), nums.end());

    // c = (a+b+c) - (a) - (b)
    int val = nums[6] - nums[0] - nums[1];
    cout << nums[0] << " " << nums[1] << " " << val;;
}

int main() {
	// setIO("problemname");

    tc();
}
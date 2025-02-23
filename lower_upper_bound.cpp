#include<bits/stdc++.h>

using namespace std;

int main(){
    map<int, int> m;
    m[3] = 5; // [(3, 5)]
    m[11] = 4; // [(3, 5); (11, 4)]
    m[10] = 491; // [(3, 5); (10, 491); (11, 4)]
    cout << m.lower_bound(4)->first << " " << m.lower_bound(4)->second << '\n'; // 10 491
    cout << m.upper_bound(1)->first << " " << m.upper_bound(1)->second << '\n'; // 11 4
    m.erase(11); // [(3, 5); (10, 491)]

    string text = "Johan said: \"heya!\" ";
    cout << text << endl;

    cout << "Enter long text: ";
    string line;
    getline(cin, line);
    cout << line;
}
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
    int n,k;
    cin >> n >> k;
    vector<string> essay;
    
    /*
     * SOLUTION 1
    */
    string word;
    int charCount = 0;
    for(int i=0; i<n; i++){
        cin >> word;
        essay.push_back(word); // for Solution 2
        
        charCount += word.length();
        if(charCount <= k){
            if(i!=0){
                // print space if not the first word
                cout << " ";
            }
            cout << word;
        }else{
            charCount = word.length();
            cout << "\n" << word;
        }
    }

    /*
     * SOLUTION 2
    */
    int charCount = 0;
    string line = "";
    for(auto word: essay){
        if(charCount + word.length() > k){
            if(line.length()>0){
                cout << line << "\n";
            }
            charCount = word.length();
            line = word;
        }else{
            charCount += word.length();
            if(line.length() > 0){
                line += " " + word;
            }else{
                line = word;
            }
        }
    }
    if(line.length() >= 0){
        cout << line;
    }
}

int main() {
	setIO("word");

    tc();
}
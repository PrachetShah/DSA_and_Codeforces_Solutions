#include<bits/stdc++.h>

using namespace std;

vector<char> addString(string s){
    vector<char> ans(s.begin(), s.end());
    return ans;
}

void createMapLeft(map<char, char> &left, vector<char> a){
    for(int i=0; i<a.size()-1; i++){
        left[a[i]] = a[i+1];
    }
}

void createMapRight(map<char, char> &right, vector<char> a){
    for(int i=1; i<a.size(); i++){
        right[a[i]] = a[i-1];
    }
}

int main(){
    char move;
    cin >> move;

    string sentence;
    cin >> sentence;

    vector<char> a = addString("qwertyuiop");
    vector<char> b = addString("asdfghjkl;");
    vector<char> c = addString("zxcvbnm,./");

    map<char, char> right;
    createMapRight(right, a);
    createMapRight(right, b);
    createMapRight(right, c);

    map<char, char> left;
    createMapLeft(left, a);
    createMapLeft(left, b);
    createMapLeft(left, c);

    if(move == 'R'){
        for(int i=0; i<sentence.length(); i++){
            sentence[i] = right[sentence[i]];
        }
    }else{
        for(int i=0; i<sentence.length(); i++){
            sentence[i] = left[sentence[i]];
        }
    }
    cout << sentence << endl;
    return 0;
}
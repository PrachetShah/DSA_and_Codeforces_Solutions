#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int cntLower = 0, cntUpper = 0;

    vector<int> lower;
    vector<int> upper;

    for(int i=0; i<s.size(); i++){
        if(s[i]>=97 && s[i]<=122){
            cntLower++;
            lower.push_back(i);
        }else{
            cntUpper++;
            upper.push_back(i);
        }
    }

    if(cntUpper > cntLower){
        for(int i=0; i<lower.size(); i++){
            s[lower[i]] = s[lower[i]] - 32;
        }
    }else{
        for(int i=0; i<upper.size(); i++){
            s[upper[i]] = s[upper[i]] + 32;
        }
    }

    cout << s << endl;

    return 0;
}
    #include<bits/stdc++.h>

    using namespace std;

    using ll = long unsigned;

    void tc(){
        string s;
        cin >> s;
        ll repCount = 0;
        ll index = 0;
        while(index < s.length()){
            ll currIndex = index;
            ll curr = 0;
            while(s[index] == s[currIndex]){
                currIndex++;
                curr++;
            }
            index = currIndex;
            repCount = max(repCount, curr);
        }
        cout << repCount;
    }

    int main(){
        tc();
    }
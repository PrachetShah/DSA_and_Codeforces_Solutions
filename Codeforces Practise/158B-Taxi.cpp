#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> s(n, 0);
    int four=0, three=0, two=0, one=0;
    int ans = 0;
    
    for(int i=0; i<n; i++){
        cin >> s[i];
        if(s[i] == 1){
            one++;
        }else if(s[i] == 2){
            two++;
        }else if(s[i] == 3){
            three++;
        }else{
            four++;
        }

    }

    ans += four;

    while(three){
        if(one){
            three--;
            one--;
        }else{
            three--;
        }
        ans++;
    }

    while(two){
        if(two >= 2){
            two -= 2;
        }else{
            one -= 2;
            two -= 1;
        }
        ans++;
    }

    while(one > 0){
        if(one >= 4){
            one -= 4;
        }else{
            one = 0;
        }
        ans++;
    }

    cout << ans << endl;

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string colors;
    cin >> colors;

    int i=0, ans=0;
    while(true){
        if(i == colors.length()-1){
            break;
        }
        if(colors[i] == colors[i+1]){
            ans++;
            colors.erase(colors.begin()+i+1);
        }else{
            i++;
        }
    }

    cout << ans << endl;
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){  
    int n;
    cin >> n;
    int x=0;
    string temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        if(temp[0]=='+' || temp[1]=='+'){
            x++;
        }else{
            x--;
        }
    }
    cout << x;
    return 0;
}

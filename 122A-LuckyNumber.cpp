#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> nums = {4, 7, 47, 77, 447, 474, 477, 744 , 747, 777};
    bool flag = true;
    for(int i=0; i<10; i++){
        if(n < nums[i]){
            break;
        }
        if(n%nums[i] == 0){
            cout << "YES" << endl;
            flag = false;
            break;
        }
    }
    if(flag){
        cout << "NO" << endl;
    }
    return 0;
}
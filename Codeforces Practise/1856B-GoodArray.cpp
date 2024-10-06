#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        long long sum=0, cnt_1=0;

        for(auto x:arr){
            sum += x;
            if(x==1){
                cnt_1++;
            }
        }
        if(sum >= cnt_1+n && n>1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
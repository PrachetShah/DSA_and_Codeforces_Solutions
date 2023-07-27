#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int cnt = 0;
    for(int i=0; i<n; ++i){
        if(a[i] == 1){
            if(i>0 && a[i-1]==0){
                a[i] = 0;
                cnt++;
            }else if(a[i]==2){
                if(i>0 && (a[i-1]==0 || a[i-1]==1)){
                    a[i]=1;
                    cnt++;
                }else if(i<n-1 && (a[i+1]==0 || a[i+1]==1)){
                    a[i] = 1;
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
}
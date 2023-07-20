#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    if(n > m){
        swap(m , n);
    }

    if(n%2 != 0){
        cout << "Akshat";
    }else{
        cout << "Malvika";
    }
    return 0;
}
#include<iostream>
#include<cmath>

using namespace std;

int main(){

    string a, b;

    cin >> a >> b;

    for(int i=0; i<a.length(); i++){
        if(a[i] >= 'A' && a[i] <= 'Z'){
            a[i] = a[i] + 97 - 'A';
        }
        if(b[i] >= 'A' && b[i] <= 'Z'){
            b[i] = b[i] + 97 - 'A';
        }
    }
    // cout << a << " " << b <<endl;

    if(a > b){
        cout << 1;
    }else if( a == b){
        cout << 0;
    }else{
        cout << -1;
    }

    return 0;
}
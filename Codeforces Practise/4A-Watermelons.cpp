#include<iostream>
#include<cmath>

using namespace std;

int main(){

    int m;
    cin >> m;

    if(m>2 && m%2 == 0){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}
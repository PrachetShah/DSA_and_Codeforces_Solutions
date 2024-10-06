#include<bits/stdc++.h>

using namespace std;

int main(){
    string input;
    cin >> input;
    if(input[0]>='a' && input[0]<='z'){
        input[0] = input[0] - 32;
    }

    cout << input;
    return 0;
}
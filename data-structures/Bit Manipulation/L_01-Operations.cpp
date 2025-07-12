#include<bits/stdc++.h>

using namespace std;

int main(){
    int a = 6;
    // AND Operator
    cout << a << " " << (a&1) << " " << (a&0) << " " << (a&a) << endl;
    // OR Operator
    cout << a << " " << (a|1) << " " << (a|0) << " " << (a|a) << endl;
    // Left Shift Operator -> a*2^k
    cout << a << " " << (a<<1) << " " << (a<<2) << " " << (a<<3) << endl;
    // Right Shift Operator -> a/2^k
    cout << a << " " << (a>>1) << " " << (a>>2) << " " << (a>>3) << endl;
}
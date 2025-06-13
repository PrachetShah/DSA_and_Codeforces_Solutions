#include<bits/stdc++.h>

using namespace std;

int val(char c){
    if(c>='0' && c<='9'){
        return (int)c-'0';
    }else{
        return (int)c-'A' + 10;
    }
}

int toDeci(string s, int base){
    int power = 1;
    int ans = 0;
    for(int i=s.length()-1; i>=0; i--){
        if (val(s[i]) >= base) {
            printf("Invalid Number");
            return -1;
        }

        int num = val(s[i]);
        ans += num*power;
        power = power*base;
    }
    return ans;
}

char reVal(int num){
    if(num >=0 && num<=9){
        return (char)'0'+num;
    }else{
        return (char)'A'+num-10;
    }
}

string fromDeci(int num, int base){
    string res = "";
    while(num > 0){
        // IMP
        res += reVal(num%base);
        // IMP
        num = num/base;   
    }
    reverse(res.begin(), res.end());
    return res;
}

string convert(string s, int a, int b){
    // convert to decimal from base a
    int num = toDeci(s, a);
    // decimal to base b
    string val = fromDeci(num, b);
    return val;
}

int main(){
    string s = "10B";
    int a = 16;
    int b = 10;

    string s2 = "10011";
    int a2 = 2;
    int b2 = 8;

    string num1 = convert(s, a, b);
    cout << num1 << endl;

    string num2 = convert(s2, a2, b2);
    cout << num2;
}
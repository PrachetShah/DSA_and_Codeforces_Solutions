#include<bits/stdc++.h>

using namespace std;

int main(){
    string input;
    cin >> input;

    string ans;

    for(int i=0; i < input.length(); i++){
        // Char is uppercase 
        if(input[i] >= 65 && input[i] <= 90){
            input[i] = input[i] + 32;
        }
        // Char is from the given VOWELS list -> a e i o u y
        if(input[i]=='a' || input[i]=='i' || input[i]=='e' || input[i]=='o' || input[i]=='u' || input[i]=='y'){
            continue;
        }else{
            ans += '.';
            ans += input[i];
        }
    }

    cout << ans << endl;
    return 0;
}
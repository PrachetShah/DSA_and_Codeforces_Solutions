#include<bits/stdc++.h>

using namespace std;

int main(){
    string word;
    cin >> word;
    // one word string
    if(word.length() == 1){
        if(word[0] >= 97 && word[0] <=122){
            word[0] = word[0] - 32;
            cout << word;
        }else{
            word[0] = word[0] + 32;
            cout << word << endl;
        }
    }else{
        // Check if all uppercase
        bool allUpper = true;
        for(int i=0; i<word.length(); i++){
            if(word[i]>=97 && word[i]<=122){
                allUpper = false;
                break;
            }
        }
        if(allUpper){
            for(int i=0; i<word.length(); i++){
                word[i] = word[i] + 32;
            }
            cout << word << endl;
        }else{
            // Check if all letters except the first are uppercase
            bool firstLower = true;
            for(int i=1; i<word.length(); i++){
                if(word[i]>=97 && word[i]<=122){
                    firstLower = false;
                    break;
                }
            }
            if(firstLower && (word[0]>=97 && word[0]<=122)){
                word[0] = word[0] - 32;
                for(int i=1; i<word.length(); i++){
                    word[i] = word[i] + 32;
                }
                cout << word << endl;
            }else{
                cout << word << endl;
            }
        }
    }
    return 0;
}
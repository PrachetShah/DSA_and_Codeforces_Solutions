#include<bits/stdc++.h>

using namespace std;

int main(){
    string input;
    cin >> input;

    unordered_map<int, int> counts;
    for(int i=0; i<input.length(); i++){
        counts[input[i]-'a']++;
    }

    int countOne = 0;
    if(input.length()%2 == 0){
        for(auto a: counts){
            if(a.second%2 == 1){
                cout << "Not a Palindrome Permutation\n";
                break;
            }
        }
        cout << "Palindrome Permutation\n";
    }else{
        for(auto a: counts){
            if(a.second%2 == 1){
                countOne++;
                if(countOne > 1){
                    cout << "Not a Palindrome Permutation\n";
                    break;
                }
            }
        }
        cout << "Palindrome Permutation\n";
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
    string input;
    cin >> input;

    string output;
    vector<int> nums;
    for(int i=0; i<input.length(); i++){
        if(input[i] != '+'){
            nums.push_back(input[i]-'0');
        }
    }
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size()-1; i++){
        output += to_string(nums[i]) + "+";
    }

    output += to_string(nums[nums.size()-1]);

    cout << output;
    return 0;
}
#include<map>
#include<unordered_map>
#include<iostream>

using namespace std;

int main(){
    // creation
    unordered_map<string, int> m;

    // insertion
    m["prachet"] = 1;
    m.insert({"kevin", 2});

    // searc
    cout << m["prachet"] << endl;
    cout << m.at("kevin") << "\n";

    for(auto s:m){
        cout << s.first << " " << s.second << "\n";
    }

    return 0;
}
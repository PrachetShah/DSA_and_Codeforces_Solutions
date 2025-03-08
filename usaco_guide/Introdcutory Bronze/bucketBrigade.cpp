#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

// use it in bracket -> a%(MOD);
#define MOD 1000000007;

using ll = long long;
using vll = vector <ll>;
using ii = pair <ll, ll>;
using vii = vector <ii>;

// the argument is the input filename without the extension
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void print(vector<vector<char>> farm){
    for(int i=0; i<farm.size(); i++){
        for(int j=0; j<farm[0].size(); j++){
            cout << farm[i][j] << " ";
        }
        cout << "\n";
    }
}

void tc(){
    vector<vector<char>> farm(10, vector<char>(10, '.'));

    char val;
    pair<int, int> barn;
    pair<int, int> lake;
    pair<int, int> rock;

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> val;
            if(val=='B'){
                barn = make_pair(i, j);
            }
            if(val=='L'){
                lake = make_pair(i, j);
            }
            if(val == 'R'){
                rock = make_pair(i, j);
            }
            farm[i][j] = val;
        }
    }
    // cout << barn.first << " " << barn.second << "\n";
    // cout << lake.first << " " << lake.second << "\n";
    // print(farm);
    int cows = abs(barn.first-lake.first) + abs(barn.second-lake.second) - 1;

    // if rock, barn, and lake are in same column
    if(rock.first==lake.first && lake.first==barn.first
        && ((lake.second < rock.second && rock.second < barn.second) || 
        (barn.second < rock.second && rock.second < lake.second))
    ){
        cows += 2;
    }

    // if they are in same row
    if(rock.second==lake.second && lake.second==barn.second
        && ((lake.first < rock.first && rock.first < barn.first) || 
        (barn.first < rock.first && rock.first < lake.first))
    ){
        cows += 2;
    }

    cout << cows << endl;
}

int main() {
	setIO("buckets");
    tc();
    // int t;
    // cin >> t;
    // cout << t;
}
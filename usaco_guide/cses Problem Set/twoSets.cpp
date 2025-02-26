/*
To be able to divide the set into two different sets of equal sum, n must be of the form 4k or 4k+3,

case [i] -> n = 4k put first n/4 numbers and last n/4 in first set, and remaining n/2 numbers in second set, for eg, n= 8 {1,2,7,8}, {3,4,5,6}

case [ii] -> n = 4k + 3

observation- 4n 4n+1 4n+2 4n+3, then 4n + 4n+3 == 4n + 1 + 4n + 2, therefore make partition accordingly.
*/

#include<bits/stdc++.h>

using namespace std;

using ll = long long;

void tc(){
    int n;
    cin >> n;


    if(n%4 == 1 || n%4==2){
        cout << "NO\n";
    }else if(n%4==3){
        cout << "YES\n";
        cout << n/2 << "\n";
        for(int i=2; i<=n/2; i+=2){
            cout << i << " " << n-i << " ";
        }
        cout << n << "\n";

        cout << n/2+1 << "\n";
        for(int i=1; i<=n/2; i+=2){
            cout << i << " " << n-i << " ";
        }
    }else{
        cout << "YES\n";
        cout << n/2 << "\n";
        for(int i=2; i<=n/2; i+=2){
            cout << i << " " << n-i+1 << " ";
        }
        cout << "\n" << n/2 << "\n";
        for(int i=1; i<=n/2; i+=2){
            cout << i << " " << n-i+1 << " ";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    tc();
}
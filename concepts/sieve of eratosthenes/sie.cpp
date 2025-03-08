#include<vector>
#include<iostream>

using namespace std;

using ll = long long;

void sieveOfEratosthenes(int n){
    vector<ll> prime(n, 1);

    for(int i=2; i*i <= n; i++){
        if(prime[i]){
            for(int j=i*i; j<=n; j+=i){
                prime[j] = i;
            }
        }
    }

    // print all prime numbers
    ll count = 0;
    for(int p=2; p<=n; p++){
        if(prime[p] == 1){
            // cout << p << " ";
            count++;
        }
    }
    cout << endl << count << endl;
}

int main(){
    sieveOfEratosthenes(10);
    sieveOfEratosthenes(1000);
    sieveOfEratosthenes(5000001);
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long int> a(n), b(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
        }

        long long int minA = *min_element(a.begin(), a.end());
        long long int minB = *min_element(b.begin(), b.end());

        long long int sumA = accumulate(a.begin(), a.end(), 0LL);
        long long int sumB = accumulate(b.begin(), b.end(), 0LL);
        
        long long int ans = min(minA*n+sumB, minB*n+sumA);
        cout << ans << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int n,q;
	cin >> n >> q;
	vector<vector<ll int>> planets;
	planets.push_back({-1});
	
	for(ll int i=0; i<n; i++){
	   ll int k;
	   cin >> k;
	   vector<ll int> height(k, 0);
	   for(ll int j=0; j<k; j++){
	       cin >> height[j];
	   }
	   
	   make_heap(height.begin(), height.end());
	   planets.push_back(height);
	}
	
// 	for(int j=0; j<=n; j++){
// 	    cout << "\n";
// 	    for(int k=0; k<planets[j].size(); k++){
// 	        cout << planets[j][k] << " ";
// 	    }
// 	}
	
	for(ll int j=0; j<q; j++){
	    ll int type;
	    cin >> type;
	    
	    if(type == 1){
	        ll int l,r;
	        cin >> l >> r;
	        ll int maxi=0, max_planet;
	        
	        for(ll int i=l; i<=r; i++){
	            ll int num = planets[i].front();
	            if(num > maxi){
	                maxi = num;
	                max_planet = i;
	            }
	        }
	        cout << maxi << " ";

	        reverse(planets[max_planet].begin(), planets[max_planet].end());
	        planets[max_planet].pop_back();
	        reverse(planets[max_planet].begin(), planets[max_planet].end());
	        
	    }else{
	        ll int planet, num;
	        cin >> planet >> num;
	        planets[planet].push_back(num);
	        push_heap(planets[planet].begin(), planets[planet].end());
	    }
	}

	return 0;
}

	       // for(int j=0; j<n; j++){
        // 	    cout << "\n";
        // 	    for(int k=0; k<planets[i].size(); k++){
        // 	        cout << planets[j][k] << " ";
        // 	    }
        // 	}
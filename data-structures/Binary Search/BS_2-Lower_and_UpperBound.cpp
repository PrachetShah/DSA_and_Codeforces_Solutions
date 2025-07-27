#include<bits/stdc++.h>

using namespace std;

int lowerBound(vector<int> arr, int toSearch){
    int n = arr.size();
    int ans = n;
    int low = 0, high=n-1;

    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] >= toSearch){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}

int upperBound(vector<int> arr, int toSearch){
    int n = arr.size();
    int ans = n;
    int low = 0, high=n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] > toSearch){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,3,7,8,9,9,9,11};
    int toSearch = 9;
    cout << arr.size() << endl;
    cout << lowerBound(arr, toSearch) << endl;
    cout << upperBound(arr, toSearch) << endl;
}
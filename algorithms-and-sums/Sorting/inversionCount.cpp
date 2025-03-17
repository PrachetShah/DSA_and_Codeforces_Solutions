#include<bits/stdc++.h>

using namespace std;

int merge(vector<int> &arr, int left, int mid, int right){
	int low = left;
	int high = mid+1;
    // First Modification
    int cnt = 0;
	vector<int> temp;
	while(low <= mid && high <=right){
		if(arr[low] <= arr[high]){
			temp.push_back(arr[low]);
			low++;
		}else{
			temp.push_back(arr[high]);
			high++;
            // 2 Modification
            cnt += (mid-low+1);
		}
	}
	
	while(low <= mid){
		temp.push_back(arr[low]);
		low++;
	}

	while(high <= right){
		temp.push_back(arr[high]);
		high++;
	}

	for(int i=left; i<=right; i++){
		arr[i] = temp[i-left];
	}

    return cnt;
}

int mergeSort(vector<int> &arr, int left, int right){
    int cnt = 0;
	if(left >= right){
		return cnt;
	}
	int mid = (left + right)/2;
	cnt += mergeSort(arr, left, mid);
	cnt += mergeSort(arr, mid+1, right);
	cnt += merge(arr, left, mid, right);
    return cnt;
}

template <typename T> void print(vector<T> arr){
    for(auto num: arr){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {1,0,5,2,4,5,26,2,63,66,3,0,45,2,3};
    int cnt = mergeSort(arr, 0, arr.size()-1);
    cout << "Inversion Count of Arr: " << cnt << endl;
    print(arr);
    
    vector<int> arr2 = {5, 4, 3, 2, 1};
    int cnt2 = mergeSort(arr2, 0, arr2.size()-1);
    cout << "\nInversion Count of Arr: " << cnt2 << endl;
    print(arr2);
}
#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int left, int mid, int right){
	int low = left;
	int high = mid+1;
	vector<int> temp;
	while(low <= mid && high <=right){
		if(arr[low] <= arr[high]){
			temp.push_back(arr[low]);
			low++;
		}else{
			temp.push_back(arr[high]);
			high++;
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
}

void mergeSort(vector<int> &arr, int left, int right){
	if(left >= right){
		return;
	}
	int mid = (left + right)/2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid+1, right);
	merge(arr, left, mid, right);
}

template <typename T> void print(vector<T> arr){
    for(auto num: arr){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {1,0,5,2,4,5,26,2,63,66,3,0,45,2,3};
    mergeSort(arr, 0, arr.size()-1);
    print(arr);
}
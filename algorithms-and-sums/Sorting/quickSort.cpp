#include<bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int low, int high){
	int left = low;
	int right = high;
	int pivot = arr[low];
	
	while(left < right){
		while(arr[left] <= pivot && left<=high-1){
			left++;
		}
		while(arr[right] > pivot && right>=low+1){
			right--;
		}
		if(left < right) {
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
		int temp = arr[right];
		arr[right] = arr[low];
		arr[low] = temp;
	}
	return right;
}

void quickSort(vector<int> &arr, int left, int right){
	if(left > right){
		return;
	}
	int partitionIndex = partition(arr, left, right);
	quickSort(arr, left, partitionIndex-1);
	quickSort(arr, partitionIndex+1, right);
}

template <typename T> void print(vector<T> arr){
    for(auto num: arr){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {1,0,5,2,4,5,26,2,63,66,3,0,45,2,3};
    quickSort(arr, 0, arr.size()-1);
    print(arr);
}
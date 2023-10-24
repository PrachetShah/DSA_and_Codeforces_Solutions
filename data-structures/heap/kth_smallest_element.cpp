#include <bits/stdc++.h>
using namespace std;

/*
Yaha Smallest ele pucha tha isliye MAXHEAP se nikal diya
agar largest element puchte toh MINHEAP se nikal jaata

Approach 1: Sort and return arr[k-1] -> O(nlogn)

Apprach 2: Using Heaps -> O(n-k + klogn) = O(klogn)
SC: O(k)

Step1: Store first k elements in Max Heap
Step 2: for remaining elemenst
    1. if element < heap.top()
        do heap.pop() and heap.push(element)

In this way, third smallest element will be on top of heap
*/

int KSmallestElement(int arr[], int n, int k){
    priority_queue<int> maxHeap;

    for(int i=0; i<k; i++){
        maxHeap.push(arr[i]);
    }

    for(int i=k; i<n; i++){
        if(arr[i] < maxHeap.top()){
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }

    return maxHeap.top();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int k = 3, n=10;

    cout << KSmallestElement(arr, n, k);

    return 0;
}
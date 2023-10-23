#include <bits/stdc++.h>
using namespace std;

class Heap{
    public:
        int arr[100];
        int size;

        Heap(){
            arr[0] = -1;
            size = 0;
        }

        // O(log n) -> Time to Insert
        void insert(int val){
            size++;
            int index = size;
            arr[index] = val;
            while(index > 1){
                int parent = index/2;
                if(arr[parent] < arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }else{
                    return;
                }
            }
        }

        // O(log n) -> Time to Delete
        void deleteRoot(){
            if(size == 0){
                cout << "Nothing to Delete\n";
                return;
            }

            int deleted = arr[1];
            cout << "Deleted Node with Value: " << deleted << "\n";

            // Change last element as first in heap and delete the last element
            arr[1] = arr[size];
            size--;
            
            // Take Node to its correct position or perform "propagation"
            int i = 1;
            while(i < size){
                int leftIndex = 2*i;
                int rightIndex = 2*i + 1;

                if(leftIndex < size && arr[i] < arr[leftIndex]){
                    swap(arr[i], arr[leftIndex]);
                    i = leftIndex;
                }else if(rightIndex < size && arr[i] < arr[rightIndex]){
                    swap(arr[i], arr[rightIndex]);
                    i = rightIndex;
                }else{
                    return;
                }
            }
        }

        void print(){
            for(int i=1; i<=size; i++){
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<n && arr[largest] < arr[left]){
        largest = left;
    }

    if(right<n && arr[largest] < arr[right]){
        largest = right;
    }

    // check if largest for changed or not
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteRoot();
    h.print();
    
    // Heapify the Array
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i=n/2; i>0; i--){
        heapify(arr, n, i);
    }
    cout << "Printing the Array: ";
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
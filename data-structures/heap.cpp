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

        void print(){
            for(int i=1; i<=size; i++){
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
};

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
    

    return 0;
}
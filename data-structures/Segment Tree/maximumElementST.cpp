/*
Segment tree where we can query maximum in given two indexes
*/
#include<bits/stdc++.h>

using namespace std;

template <typename T> class MaxSegmentTree{
    private:
    vector<T> ST;
    vector<T> arr;
    int n;

    int left(int node) { return 2 * node + 1; }

    // Helper function to get the right child of a node
    int right(int node) { return 2 * node + 2; }

    // Helper function to calculate the middle index
    int mid(int l, int r) { return l + (r - l) / 2; }
    
    void build(int node, int low, int high){
        if(low==high){
            ST[node] = arr[low];
            return;
        }
        int mid = (low+high)/2;
        build(left(node), low, mid);
        build(right(node), mid+1, high);
        // Max Segment tree
        ST[node] = max(ST[left(node)], ST[right(node)]);
    }

    void update(int node, int low, int high, int idx, T val){
        if(low == high){
            arr[idx] = val;
            ST[node] = val;
            return;
        }
        int mid = (low+high)/2;
        if(idx <= mid){
            update(left(node), low, mid, idx, val);
        }else{
            update(right(node), mid+1, high, idx, val);
        }
        ST[node] = max(ST[left(node)], ST[right(node)]);
    }

    T query(int node, int low, int high, int l, int r){
        // outside range of tree
        if(low>r || high<l){
            return INT_MIN;
        }
        // if nodes range is inside
        if(low>=l && high<=r){
            return ST[node];
        }
        int mid = (low+high)/2;
        T left = query(2*node+1, low, mid, l, r);
        T right = query(2*node+2, mid+1, high, l , r);
        return max(left, right);
    }

    public:
    MaxSegmentTree(vector<T> &a){
        n = a.size();
        arr = a;
        ST.resize(4*n);
        build(0, 0, n-1);
    }

    void update(int idx, T val){
        update(0, 0, n-1, idx, val);
    }

    T query(int l, int r){
        return query(0, 0, n-1, l, r);
    }

    void print(){
        for(auto num: ST){
            cout << num << " ";
        }
        cout << endl;
    }
};

int main(){

    vector<int> arr = { 1, 3, 2, 7, 9, 11 };

    MaxSegmentTree<int> st(arr);

     cout << "-------------------------------------------------" << endl;
    // Display initial information
    cout << "Segment Tree for Minimum Range Queries:"
         << endl;
    cout << "Original Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    cout << "-------------------------------------------------" << endl;

    cout << "Perform some range queries" << endl;
    cout << "Maximum in range [1, 4]: " << st.query(1, 4) << endl;
    cout << "Maximum in range [0, 5]: " << st.query(0, 5) << endl;
    cout << "Maximum in range [0, 0]: " << st.query(0, 0) << endl;

    cout << "-------------------------------------------------" << endl;

    cout << "Perform some update queries" << endl;
    st.update(1, 10);
    st.update(0, -5);
    cout << "Maximum in range [1, 4]: " << st.query(1, 4) << endl;
    cout << "Maximum in range [0, 5]: " << st.query(0, 5) << endl;
    cout << "Maximum in range [0, 0]: " << st.query(0, 0) << endl;


    return 0;
}
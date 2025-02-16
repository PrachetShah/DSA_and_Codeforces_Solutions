#include<bits/stdc++.h>

using namespace std;

template <typename T> class MinSegmentTree{
    private:
    vector<T> ST;
    vector<T> arr;
    int n;

    int left(int node){
        return 2*node+1;
    }

    int right(int node){
        return 2*node+2;
    }

    int getMid(int low, int high){
        return (low) + (high-low)/2;
    }

    void build(int node, int low, int high){
        if(low == high){
            ST[node] = arr[low];
            return;
        }

        int m = getMid(low, high);
        build(left(node), low, m);
        build(right(node), m+1, high);
        ST[node] = min(ST[left(node)], ST[right(node)]);
    }

    T query(int node, int low, int high, int l, int r){
        // when not in range
        if(low>r || high<l){
            return INT_MAX;
        }
        // for range inside
        if(low>=l && high<=r){
            return ST[node];
        }
        int m = getMid(low, high);
        T leftVal = query(left(node), low, m, l, r);
        T rightVal = query(right(node), m+1, high, l , r);
        return min(leftVal, rightVal);
    }

    void update(int node, int l, int r, int idx, T val){
        if(l==r){
            arr[idx] = val;
            ST[node] = val;
            return;
        }
        int m = getMid(l, r);
        // to propagate direction based on index
        if(idx <= m){
            update(left(node), l, m, idx, val);
        }else{
            update(right(node), m+1, r, idx, val);
        }
        ST[node] = min(ST[left(node)], ST[right(node)]);
    }

    public:
    MinSegmentTree(vector<T> &a){
        n = a.size();
        arr = a;
        ST.resize(4*n);
        build(0, 0, n-1);
    }

    T query(int l, int r){
        return query(0, 0, n-1, l, r);
    }

    void update(int idx, T val){
        update(0, 0, n-1, idx, val);
    }
};


int main(){
    vector<int> arr = { 1, 3, 2, 7, 9, 11 };

    MinSegmentTree<int> st(arr);

     cout << "-------------------------------------------------" << endl;
    // Display initial information
    cout << "Segment Tree for Minimum Range Queries:" << endl;
    cout << "Original Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    cout << "-------------------------------------------------" << endl;

    cout << "Perform some range queries" << endl;
    cout << "Minimum in range [1, 4]: " << st.query(1, 4) << endl;
    cout << "Minimum in range [0, 5]: " << st.query(0, 5) << endl;
    cout << "Minimum in range [0, 0]: " << st.query(0, 0) << endl;

    cout << "-------------------------------------------------" << endl;

    cout << "Perform some update queries" << endl;
    st.update(1, 10);
    st.update(0, -5);
    cout << "Minimum in range [1, 4]: " << st.query(1, 4) << endl;
    cout << "Minimum in range [0, 5]: " << st.query(0, 5) << endl;
    cout << "Minimum in range [0, 0]: " << st.query(0, 0) << endl;

    return 0;
}
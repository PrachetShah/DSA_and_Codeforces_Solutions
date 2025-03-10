/*
For range updates, Lazy Propagation is optimised
- Efficient for range updates: Normal updates take O(N) for Range Updates, but lazy propagation reduces it to O(log N).
- Great for large datasets: Useful in problems where updates and queries are mixed.
- Optimized Competitive Programming Performance: Essential for handling millions of operations efficiently.
*/


#include<bits/stdc++.h>

using namespace std;

template <typename T> class SumSegmentTree{
    private:
    vector<T> ST;
    vector<T> arr;
    vector<T> lazy;
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
        if(low > high){
            return;
        }
        if(low == high){
            ST[node] = arr[low];
            return;
        }

        int m = getMid(low, high);
        build(left(node), low, m);
        build(right(node), m+1, high);
        ST[node] = ST[left(node)] + ST[right(node)];
    }

    void propagate(int node, int low, int high){
        if(lazy[node] != 0){
            // theres a pending update
            ST[node] += (high-low+1)*lazy[node];

            if(low!=high){ // Not a leaf node, propagate laziness
                lazy[left(node)] += lazy[node];
                lazy[right(node)] += lazy[node];
            }

            lazy[node] = 0;
        }
    }

    T query(int node, int low, int high, int l, int r){
        propagate(node, low, high);  // Apply any pending updates

        // when not in range, it should return 0 instead of INT_MAX as one of LEFT/RIGHT can be INT_MAX, when querying in  the end
        // Out of range (Return 0 for sum queries)
        if(low>r || high<l){
            return 0;
        }
        // for range inside
        if(low>=l && high<=r){
            return ST[node];
        }
        int m = getMid(low, high);
        T leftVal = query(left(node), low, m, l, r);
        T rightVal = query(right(node), m+1, high, l , r);
        // When not in range 0 is returned, since either one of these can be INT_MAX
        return leftVal + rightVal;
    }

    void rangeUpdate(int node, int low, int high, int l, int r, T val){
        propagate(node, low, high);

        if(low > r || high<l){
            return;
        }

        if(low>=l && high<=r){
            lazy[node] += val;
            propagate(node, low, high);
            return;
        }

        int m = getMid(low, high);
        rangeUpdate(left(node), low, m, l, r, val);
        rangeUpdate(right(node), m + 1, high, l, r, val);
        ST[node] = ST[left(node)] + ST[right(node)];
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
        ST[node] = ST[left(node)] + ST[right(node)];
    }

    public:
    SumSegmentTree(vector<T> &a){
        n = a.size();
        arr = a;
        ST.resize(4*n);
        lazy.resize(4 * n, 0);
        build(0, 0, n-1);
    }

    T query(int l, int r){
        return query(0, 0, n-1, l, r);
    }

    void update(int idx, T val){
        update(0, 0, n-1, idx, val);
    }

    void rangeUpdate(int l, int r, T val) {
        rangeUpdate(0, 0, n - 1, l, r, val);
    }
};


int main(){
    vector<int> arr = { 1, 3, 2, 7, 9, 11 };

    SumSegmentTree<int> st(arr);

    cout << "-------------------------------------------------" << endl;
    // Display initial information
    cout << "Segment Tree for Sum Range Queries:" << endl;
    cout << "Original Array: ";
    // use of lambda function, passing without variable
    [](vector<int> arr){
        for(int num: arr){
            cout << num << " ";
        }
    }(arr);

    cout << endl;

    cout << "-------------------------------------------------" << endl;

    cout << "Perform some range queries" << endl;
    cout << "Sum in range [1, 4]: " << st.query(1, 4) << endl;
    cout << "Sum in range [0, 5]: " << st.query(0, 5) << endl;
    cout << "Sum in range [0, 0]: " << st.query(0, 0) << endl;

    cout << "-------------------------------------------------" << endl;
    
    cout << "Perform some update queries" << endl;
    st.update(1, 10);
    st.update(0, -5);
    cout << "Sum in range [1, 4]: " << st.query(1, 4) << endl;
    cout << "Sum in range [0, 5]: " << st.query(0, 5) << endl;
    cout << "Sum in range [0, 0]: " << st.query(0, 0) << endl;
    
    cout << "-------------------------------------------------" << endl;
    cout << "Performing Range Updates (Lazy Propagation)" << endl;
    st.rangeUpdate(1, 3, 5); // Add 5 to range [1, 3]
    cout << "Sum in range [1, 4] after update: " << st.query(1, 4) << endl;

    return 0;
}
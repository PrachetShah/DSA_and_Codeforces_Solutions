#include<bits/stdc++.h>

using namespace std;

void sortedInsert(stack<int> &st, int val){
    // ascending order
    if(st.empty() || st.top() < val){
        st.push(val);
        return;
    }
    int top = st.top();
    st.pop();
    sortedInsert(st, val);
    st.push(top);
}

void sortStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int val = st.top();
    st.pop();
    sortStack(st);
    sortedInsert(st, val);
}

void insertBottom(stack<int> &st, int val){
    if(st.empty()){
        st.push(val);
        return;
    }
    int num = st.top();
    st.pop();
    insertBottom(st, val);
    st.push(num);
}

void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int val = st.top();
    st.pop();
    cout << val << " removed\n";
    reverseStack(st);
    cout << val << " pushed\n";
    insertBottom(st, val);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(5);
    st.push(6);
    st.push(3);
    st.push(2);
    // sortStack(st);
    reverseStack(st);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}
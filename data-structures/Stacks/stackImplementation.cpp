#include<bits/stdc++.h>

using namespace std;

class Stack{
    private:
    int top;
    int* vals;
    int size;

    public:
    Stack(){
        top = -1;
        size = 10;
        vals = new int[size];
    }

    void push(int val){
        if(top == size){
            cout << "Stack is FULL\n";
            return;
        }
        top += 1;
        vals[top] = val;
        cout << val << " added to stack\n";
    }

    int pop(){
        if(top == -1){
            cout << "Stack is Empty\n";
            return -1;
        }
        int x = vals[top];
        top -= 1;
        return x;
    }

    int length(){
        return top+1;
    }
};

int main(){
    Stack s;
    cout << s.length() << endl;
    s.pop();
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
}
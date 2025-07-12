#include<bits/stdc++.h>

using namespace std;

void swap2Num(int &a, int &b){
    // swapping 2 numbers without using third variable using XOR Operator
    /**
     * Logic:
     * XOR of number with same number = 0
     * XOR:
     * 0 0 -> 0 ; 0 1 -> 1 ; 1 0 -> 1 ; 1 1 -> 0
     */

    //  first do a = a^b
    a = a^b;
    // second, do b = a^b -> (a^b)^b -> a
    b = a^b;
    // then do a = a^b again -> (a^b)^b -> (a^b)^a (from above) -> b
    a = a^b;
}

void checkIthBit(int n, int i){
    /**
     * For Eg: n=13, and i=2
     * 13 in binary is (1 1 0 1), and second bit is 1
     * count from right 3 [2] 1 0, so true
     * 
     * Method 1:
     * we can left shift 1 by i times and AND it with number
     * 13   -> 1 1 0 1
     * 1<<i -> 0 1 0 0
     * ans:    0 1 0 0 -> num
     * if num > 0 then it is set opr else it is not set
     * Basically, (n&(1<<i))
     * 
     * Method 2:
     * Right Shift Num by i times
     * and AND it with 1
     * 13>>i(2) -> 1 1
     * Basically, ((n>>i) & 1)
     */
    int leftShift = 1 << i;
    int ans1 = n&leftShift;

    int rightShift = n>>i;
    int ans2 = rightShift&1;
    cout << "Method 1: Right Shift " << i << "'th Bit is set or not for: " << n << " is " << (ans1 != 0 ? "True" : "False") << endl;
    cout << "Method 2: Left Shift  " << i << "'th Bit is set or not for: " << n << " is " << (ans2 != 0 ? "True" : "False") << endl;
    cout << endl;
}

void setIthBit(int n, int i){
    /**
     * Left Shift 1 'i' places and OR with NUM to Set it to 1
     * 
     * Basically, (n|(1<<i))
     */
    int leftShift = 1<<i;
    int ans = n|leftShift;
    cout << "Number after setting " << i << "th Bit in num " << n << " is " << ans << endl;
}

int main (){
    cout << "-------------------------------------------" << endl;
    // Swapping Two Numbers without Third Variable
    int a=6, b=5;
    cout << "Swapping 2 Number without Third Variable\n";
    cout << "Before Swapping\t" << a << " " << b << endl;
    swap2Num(a, b);
    cout << "After Swapping\t" << a << " " << b << endl;
    cout << "-------------------------------------------" << endl;

    // Checking if i'th bit is set or not
    int n=13, i=2;
    // 13 in binary is (1 1 0 1)
    cout << "Checking if i'th bit is set or not\n";
    for(int temp=0; temp<=i; temp++) checkIthBit(n, temp);
    cout << "-------------------------------------------" << endl;

    // Setting the i'th bit
    n=9, i=3;
    // 9 in binary is (1 0 0 1)
    cout << "Setting the i'th bit\n";
    for(int temp=0; temp<=i; temp++) setIthBit(n, temp);
    cout << "-------------------------------------------" << endl;
}
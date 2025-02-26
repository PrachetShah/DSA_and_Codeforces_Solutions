/*
Let's solve this problem for a particular K X K chessboard. Total number of squares in K X K chessboard is K2. 
So, number of ways the first knight can be placed is K2. Now the number of ways the second knight can be placed will be 
K2 - 1. This leads us to, the total number of ways the two knights can be placed in K X K chessboard is K2 * (K2-1)/2,
we divide by 2 because both knights are identical. Now we need to subtract number of ways the two knights attack each 
other from above equation.

For this we need to observe that the two knights attack each other when they are in a 2 X 3 or 3 X 2 block. 
The number of ways two knights can attack each other in a 2 X 3 block is 2 and number of ways two knights can attack 
each other in a 3 X 2 block is 2

Now, we just need to find the total number of 2 X 3 and 3 X 2 blocks in a K X K chessboard.  In a K X K chessboard, 
the 2*3 blocks can be arranged  in (K-1) rows (starting from the first row till the (K-1)-th row), and there are (K-2)
ways to position them in columns (starting from the first column till the (K-2)-th column) which gives us 
(K-1)*(K-2) ways to place a 2 X 3 block in a K X K chessboard. Similarly, we can place a 3 X 2 block in (K - 1) * (K - 2) ways. 

So, the total number of ways two knights can attack each other in a K X K chessboard will be sum of 2 * number of 2 X 3 blocks 
and 2 * number of 3 X 2 blocks, which is 4 * (K - 1) * (K - 2). It is every important to note that no 2 ways of attacking are 
same in the derived formula.

Hence the total number of ways Two Knights can be placed in a K X K chessboard such that they don't attack each other is:

(K2 * (K2 - 1)) / 2 - (4 * (K - 1) * (K - 2)) 
*/
#include<bits/stdc++.h>

using namespace std;

using ll = long long;

long calculateWays(int K) {
    long totalWays = ((long) K * K * (K * K - 1)) / 2;
    long attackingWays = 4 * (K - 1) * (K - 2);

    long ans = totalWays - attackingWays;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cout << calculateWays(i) << "\n";
    }
}
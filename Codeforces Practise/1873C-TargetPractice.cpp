#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        char arr[10][10];
        int score = 0;

        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                cin >> arr[i][j];
                if(arr[i][j] == 'X'){
                    int iVal=i, jVal=j;
                    // getting values greater than 5 to be in range 0-4 for adding scores
                    if(i>4){
                        iVal = 9 - i;
                    }
                    if(j>4){
                        jVal = 9 - j;
                    }

                    // if j < i, then score would be value of j index, else it will be value of i index
                    if(jVal < iVal){
                        score += jVal+1;
                    }else{
                        score += iVal+1;
                    }
                    // cout << "j = " << jVal << " & iMax = " << i << " & i=" << iVal << endl;
                    // cout << "Score Added: " << jVal+1 << endl;
                }
            }
        }
        // cout << "Score: " <<score <<endl;
        cout << score << endl;
    }
}
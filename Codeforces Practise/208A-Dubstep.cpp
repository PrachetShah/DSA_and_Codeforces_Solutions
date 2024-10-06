#include<bits/stdc++.h>

using namespace std;

int main(){
    string song;
    cin >> song;

    int flag = 1;
    for(int i=0; i<song.length(); i++){
        if(song[i]=='W' && i < song.length()-2 && song[i+1]=='U' && song[i+2]=='B'){
            i += 2;
            if(!flag){
                cout << " ";
            }
            continue;
        }else{
            flag = 0;
            cout << song[i] << "";
        }
    }
    return 0;
}
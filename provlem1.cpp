#include<bits/stdc++.h>

using namespace std;

int findShort(string beginWord, string endWord, vector<string> wordList){
    // Set to store all the words
    unordered_set<string> wordSet(wordList.begin(), wordList.end());

    // endword exists
    if(wordSet.find(endWord) == wordSet.end()){
        return 0;
    }

    queue<string> wordQueue;
    wordQueue.push(beginWord);
    int distance = 1;

    while(!wordQueue.empty()){
        int n = wordQueue.size();
        for(int i=0; i<n; i++){
            string curr = wordQueue.front();
            wordQueue.pop();

            if(curr==endWord){
                return distance;
            }

            for(int j=0; j<curr.length(); j++){
                char og = curr[j];
                for(char c='a'; c<='z'; c++){
                    curr[j] = c;
                    if(wordSet.find(curr) != wordSet.end()){
                        wordSet.erase(curr);
                        wordQueue.push(curr);
                    }
                }
                curr[j] = og;
            }
        }
        distance++;
    }
    return 0;
}

/*
o(n^2 m)
begin: hit
WordSet: hot, dot, dog, lot, log, cog
Q: hit

1 
hit
j=0 -> h : a-z
j=1 -> i : a-z -> hot
    erase(hot), q: hot
j=2 -> t : a-z
distance++ -> 2

2
q: hot
j=0 -> h : a-z -> dot, lot
    q: dot, lot, set: dog, log, cog


4: 
log
l -> c -> cog q.append(q)

5:
    word = cog
*/

int main(){
    // vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    vector<string> wordList = {"hot","dot","dog","lot","log"};
    string beginWord = "hit";
    string endWord = "dot";

    cout << "Shortest transormation: " << findShort(beginWord, endWord, wordList);
    return 0;
}
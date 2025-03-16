// Leetcode Hard
// TC: O(n*m)
// SC: O(n*m)
#include<bits/stdc++.h>
using namespace std;

int wordLadder(string beginWord, string endWord, vector<string> wordList){
    // store all words into set for easier access
    unordered_set<string> wordSet(wordList.begin(), wordList.end());

    // if endword not in set then return 0
    if(wordSet.find(endWord) == wordSet.end()){
        return 0;
    }

    // init a queue and start checking
    queue<string> wordQueue;
    wordQueue.push(beginWord);

    int ladder = 1;
    while(!wordQueue.empty()){
        int n = wordQueue.size();
        for(int i=0; i<n; i++){
            string curr = wordQueue.front();
            wordQueue.pop();
            
            // check if word found
            if(curr == endWord){
                return ladder;
            }
            
            // check all words which differ by one character of popped word
            for(int j=0; j<curr.length(); j++){
                char og = curr[j];
                for(char c='a'; c<='z'; c++){
                    if(c==og){
                        // since same word
                        continue;
                    }
                    curr[j] = c;
                    // if new word in set, then add to queue
                    if(wordSet.find(curr) != wordSet.end()){
                        wordQueue.push(curr);
                        // remove to prevent revisiting
                        wordSet.erase(curr);
                    }
                }
                // restore original
                curr[j] = og;
            }
        }
        // increment distance after processing level
        ladder++;
    }
    // no ans found
    return 0;
}

int main(){
    string b = "hit";
    string e = "cog";
    vector<string> words = {"hot","dot","dog","lot","log","cog"};
    cout << "Shortest Transformation Sequence length: " << wordLadder(b, e, words);
}
#include<bits/stdc++.h>

using namespace std;

class Trie{
    public:
    struct Node{
        bool isWord = false;
        vector<Node*> child{vector<Node*> (26, NULL)};
    } *root, *curr;

    void dfsWithPrefix(Node* curr, string &word, vector<string> &result){
        if(result.size()==3){
            return;
        }
        if(curr->isWord){
            result.push_back(word);
        }
        // run DFS on all possible paths
        for(char c='a'; c<='z'; c++){
            if(curr->child[c-'a']){
                word += c;
                dfsWithPrefix(curr->child[c-'a'], word, result);
                word.pop_back();
            }
        }
    }

    Trie(){
        root = new Node();
    }

    void insert(string s){
        curr = root;
        for(char c: s){
            if(!curr->child[c-'a']){
                curr->child[c-'a'] = new Node();
            }
            curr = curr->child[c-'a'];
        }
        // end of word, mark as completed
        curr->isWord = true;
    }

    vector<string> getWordsStartingWith(string &prefix){
        curr = root;
        vector<string> result;
        // move curr to its prefix and then search for words
        for(char &c: prefix){
            if(!curr->child[c-'a']){
                return result;
            }
            curr = curr->child[c-'a'];
        }
        dfsWithPrefix(curr, prefix, result);
        return result;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* trie = new Trie();
        vector<vector<string>> result;

        for(auto word: products){
            trie->insert(word);
        }
        string prefix;
        for(char c:searchWord){
            prefix += c;
            result.push_back(trie->getWordsStartingWith(prefix));
        }
        return result;
    }
};
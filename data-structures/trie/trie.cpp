#include<bits/stdc++.h>

using namespace std;


class TrieNode{
    public:

    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    private:
    void insertUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        
        // present case
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            // absent case
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // RECURSION
        insertUtil(child, word.substr(1));
    }

    bool searchUtil(TrieNode* root, string word){
        // base
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL){
            // present
            child = root->children[index];
        }else{
            // absent
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    void deleteUtil(TrieNode* root, string word){
        // base
        if(word.length() == 0){
            root->isTerminal = false;
            cout << "Word Deleted" << endl;
            return;
        }

        int index = word[0]-'a';
        TrieNode* child;

        if(root->children[index] != NULL){
            // present
            child = root->children[index];
        }else{
            cout << "Word not present in Trie\n";
            return;
        }
        deleteUtil(child, word.substr(1));
    }

    bool isEmpty(TrieNode* root){
        for (int i = 0; i <26; i++)
            if (root->children[i])
                return false;
        return true;
    }

    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    // O(Length of Word)
    void insertWord(string word){
        insertUtil(root, word);
    }

    // O(L)
    bool searchWord(string word){
        return searchUtil(root, word);
    }

    void deleteWord(string word){
        deleteUtil(root, word);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Trie* t = new Trie();
    t->insertWord("abcd");
    t->insertWord("abcde");
    t->insertWord("abcdef");

    cout << "Present or Not? \n";
    cout << "abc: " << t->searchWord("abc") << endl;
    cout << "abcd: " << t->searchWord("abcd") << endl;
    cout << "abcde: " << t->searchWord("abcde") << endl;
    cout << "abcdde: " << t->searchWord("abcdde") << endl;

    t->deleteWord("abcd");
    cout << "abcd: " << t->searchWord("abcd") << endl;

    t->deleteWord("acd");
    return 0;
}
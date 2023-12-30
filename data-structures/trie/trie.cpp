/*
Trie Data Structure
Trie is a type of k-ary search tree used for storing and searching a specific key from a set. Using Trie, search 
complexities can be brought to optimal limit (key length). 

Advantages of tries
1. In tries the keys are searched using common prefixes. Hence it is faster. The lookup of keys depends upon the 
height in case of binary search tree. 
2. Tries take less space when they contain a large number of short strings. As nodes are shared between the keys.
3. Tries help with longest prefix matching, when we want to find the key.

Comparison of tries with hash table
1. Looking up data in a trie is faster in worst case as compared to imperfect hash table.
2. There are no collisions of different keys in a trie.
3. In trie if single key is associated with more than one value then it resembles buckets in hash table.
4. There is no hash function in trie.
5. Sometimes data retrieval from tries is very much slower than hashing.
6. Representation of keys a string is complex. For example, representing floating point numbers using strings 
is really complicated in tries.
7. Tries always take more space than hash tables.

Applications of tries
1. Tries has an ability to insert, delete or search for the entries. Hence they are used in building dictionaries 
such as entries for telephone numbers, English words.
2. Tries are also used in spell-checking softwares.
*/

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
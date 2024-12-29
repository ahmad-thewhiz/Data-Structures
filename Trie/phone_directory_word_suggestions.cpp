#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        char ch = word[0];
        int idx = ch - 'a';
        TrieNode* child;

        if (root->children[idx] != nullptr) {
            child = root->children[idx];
        } else {
            child = new TrieNode(ch);
            root->children[idx] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string word) {
        word.erase(remove(word.begin(), word.end(), ' '), word.end());
        insertUtil(root, word);
    }

    void printSuggestions(TrieNode* curr, vector<string>& temp, string prefix) {
        if (curr->isTerminal) {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* next = curr->children[ch - 'a'];

            if (next != nullptr) {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str) {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.length(); i++) {
            char lastch = str[i];

            prefix.push_back(lastch);

            // Check for lastch
            TrieNode* curr = prev->children[lastch - 'a'];

            // If not found, stop further processing
            if (curr == nullptr) {
                break;
            }

            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            prev = curr;
        }
        return output;
    }
};

// Time Complexity
// Insertion - O(lengthOf(word))
// Searching - O(lengthOf(word))
// Deletion - O(lengthOf(word))

vector<vector<string>> phoneDirectory(vector<string>& contactList, string& queryStr) {
    Trie* t = new Trie();

    // Insert
    for (int i = 0; i < contactList.size(); i++) {
        string str = contactList[i];
        t->insert(str);
    }

    return t->getSuggestions(queryStr);
}

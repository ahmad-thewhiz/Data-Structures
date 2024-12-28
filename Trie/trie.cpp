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

        char ch = toupper(word[0]);
        int idx = ch - 'A';
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

    bool searchUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            return root->isTerminal;
        }

        char ch = toupper(word[0]);
        int idx = ch - 'A';
        TrieNode* child;

        if (root->children[idx] != nullptr) {
            child = root->children[idx];
        } else {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool search(string word) {
        word.erase(remove(word.begin(), word.end(), ' '), word.end());
        return searchUtil(root, word);
    }

    bool deletionUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            if (root->isTerminal) {
                root->isTerminal = false;
                return true;
            }
            return false;
        }

        char ch = toupper(word[0]);
        int idx = ch - 'A';
        TrieNode* child;

        if (root->children[idx] != nullptr) {
            child = root->children[idx];
        } else {
            return false;
        }

        bool canDeleteChild = deletionUtil(child, word.substr(1));

        if (canDeleteChild && !child->isTerminal) {
            for (int i = 0; i < 26; i++) {
                if (child->children[i] != nullptr) {
                    return false; // Child has other children, cannot delete
                }
            }
            delete child;
            root->children[idx] = nullptr;
        }

        return true;
    }

    bool deletion(string word) {
        word.erase(remove(word.begin(), word.end(), ' '), word.end());
        return deletionUtil(root, word);
    }
};

int main() {
    Trie* t = new Trie();

    // Insert words
    t->insert("Hello");
    t->insert("Hell");
    t->insert("World");
    t->insert("Code");

    // Search words
    cout << "Search 'Hello': " << (t->search("Hello") ? "Found" : "Not Found") << endl;
    cout << "Search 'Hell': " << (t->search("Hell") ? "Found" : "Not Found") << endl;
    cout << "Search 'World': " << (t->search("World") ? "Found" : "Not Found") << endl;
    cout << "Search 'Coding': " << (t->search("Coding") ? "Found" : "Not Found") << endl;

    // Delete words
    cout << "Delete 'Hello': " << (t->deletion("Hello") ? "Deleted" : "Not Found") << endl;
    cout << "Search 'Hello' after deletion: " << (t->search("Hello") ? "Found" : "Not Found") << endl;

    cout << "Delete 'Hell': " << (t->deletion("Hell") ? "Deleted" : "Not Found") << endl;
    cout << "Search 'Hell' after deletion: " << (t->search("Hell") ? "Found" : "Not Found") << endl;

    delete t;
    return 0;
}

// Time Complexity
// Insertion - O(lenghtOf(word))
// Searching - O(lenghtOf(word))
// Deletion - O(lengthOf(word))

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// prefix function
vector<int> computePrefixFunction(const string& pattern) {
    int m = pattern.length();
    vector<int> prefix(m);
    prefix[0] = 0;
    int k = 0;

    for (int q = 1; q < m; q++) {
        while (k > 0 && pattern[k] != pattern[q]) {
            k = prefix[k - 1];
        }
        if (pattern[k] == pattern[q]) {
            k++;
        }
        prefix[q] = k;
    }

    return prefix;
}

// KMP Matcher Algorithm
void KMPSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> prefix = computePrefixFunction(pattern);
    int q = 0;

    for (int i = 0; i < n; i++) {
        while (q > 0 && pattern[q] != text[i]) {
            q = prefix[q - 1];
        }
        if (pattern[q] == text[i]) {
            q++;
        }
        if (q == m) {
            cout << "Pattern occurs with shift " << (i - m + 1) << endl;
            q = prefix[q - 1];
        }
    }
}

int main() {
    string text = "abxabcabcaby";
    string pattern = "abcaby";

    KMPSearch(text, pattern);

    return 0;
}

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

// Function to precompute the mismatch shift table
void precomputeShifts(const string& pattern, unordered_map<char, int>& mismatchShiftsTable) {
    int len = pattern.length();
    for (int i=0; i<len; i++) {
        char ch = pattern[i];
        int maxShift = max(1, len - i - 1);
        mismatchShiftsTable[ch] = maxShift;
    }
}

// Boyer-Moore search function
int boyerMooreSearch(const string& text, const string& pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();
    unordered_map<char, int> mismatchShiftsTable;

    // Precompute the mismatch shift table
    precomputeShifts(pattern, mismatchShiftsTable);

    int numOfSkips = 0;

    for (int i = 0; i <= textLength - patternLength; i += numOfSkips) {
        numOfSkips = 0;
        for (int j = patternLength - 1; j >= 0; j--) {
            if (pattern[j] != text[i + j]) {
                if (mismatchShiftsTable.find(text[i + j]) != mismatchShiftsTable.end()) {
                    numOfSkips = mismatchShiftsTable[text[i + j]];
                } else {
                    numOfSkips = patternLength;
                }
                break;
            }
        }
        if (numOfSkips == 0) return i; // Match found
    }
    return -1; // No match found
}

int main() {
    string pattern = "example";
    string text = "this is an example text containing the word example.";

    int position = boyerMooreSearch(text, pattern);

    if (position != -1) {
        cout << "Pattern found at position: " << position << endl;
    } else {
        cout << "Pattern not found." << endl;
    }

    return 0;
}

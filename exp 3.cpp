#include <iostream>
#include <string>
using namespace std;

int main() {
    string text, pattern;

    cout << "Enter the main string (text): ";
    getline(cin, text);

    cout << "Enter the pattern string: ";
    getline(cin, pattern);

    int n = text.length();
    int m = pattern.length();
    bool found = false;

    // Brute Force String Matching
    for (int i = 0; i <= n - m; i++) {
        int j;

        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == m) {
            cout << "Pattern found at index: " << i << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Pattern not found in the given text." << endl;
    }

    return 0;
}


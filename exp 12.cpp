#include <iostream>
#include <ctime>
using namespace std;

#define d 256   // number of characters (ASCII)
#define q 101   // a prime number for hashing

void rabinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text window
    int h = 1;

    // Compute h = pow(d, m-1) % q
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Compute initial hash values
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    bool found = false;

    // Slide the pattern over text
    for (i = 0; i <= n - m; i++) {

        // Check hash values
        if (p == t) {
            // Verify characters
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == m) {
                cout << "Pattern found at index: " << i << endl;
                found = true;
            }
        }

        // Compute next window hash
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // Handle negative value
            if (t < 0)
                t += q;
        }
    }

    if (!found)
        cout << "Pattern not found.\n";
}

int main() {
    string text, pattern;

    cout << "Enter text: ";
    cin >> text;

    cout << "Enter pattern: ";
    cin >> pattern;

    clock_t start, end;

    start = clock();
    rabinKarp(text, pattern);
    end = clock();

    double cpu_time = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nCPU Execution Time: " << cpu_time << " seconds\n";

    return 0;
}

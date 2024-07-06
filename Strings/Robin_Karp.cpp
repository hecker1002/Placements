#include <bits/stdc++.h>
using namespace std;

int val(char ch) {
    return ch - 'A' + 1;  // Adjust this function if the text includes lowercase characters
}

int robin_karp_match(string text, string pattern) {
    int m = pattern.size();
    int n = text.size();

    if (m > n) return 0;  // Pattern is longer than the text

    const int base = 26;  // Number of unique characters (assuming only uppercase)
    const int prime = 5381;  // A large prime number

    int hash_patt = 0;
    int hash_text = 0;
    int h = 1;

    // The value of h would be "pow(base, m-1) % prime"
    for (int i = 0; i < m - 1; i++) {
        h = (h * base) % prime;
    }

    // Calculate the hash value of the pattern and the first window of text
    for (int i = 0; i < m; i++) {
        hash_patt = (base * hash_patt + val(pattern[i])) % prime;
        hash_text = (base * hash_text + val(text[i])) % prime;
    }

    int cnt = 0;  // Frequency of times the pattern matches in the text

    // Slide the pattern over text one by one
    for (int i = 0; i <= n - m; i++) {
        // Check the hash values of the current window of text and the pattern
        if (hash_patt == hash_text) {
            // If the hash values match, check for characters one by one
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cnt++;
            }
        }

        // Calculate the hash value for the next window of text: Remove the leading digit, add the trailing digit
        if (i < n - m) {
            hash_text = (base * (hash_text - val(text[i]) * h) + val(text[i + m])) % prime;

            // We might get a negative value of hash_text, converting it to positive
            if (hash_text < 0) {
                hash_text = (hash_text + prime);
            }
        }
    }
    return cnt;
}

int main() {
    string text = "AABAAC";
    string pattern = "BAA";

    int cnt = robin_karp_match(text, pattern);

    cout << cnt << endl;

    return 0;
}

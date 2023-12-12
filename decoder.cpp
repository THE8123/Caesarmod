#include <bits/stdc++.h>

using namespace std;

const int alpha = ('z' - 'a' + 1);

int main() {
    string s, key;
    getline(cin, s);
    getline(cin, key);

    int n = s.size();
    string result = s;
    int i = 0, j = 0;
    while (i < n) {
        int block = 0, move = 0;

        for (int k = j; k < j + 3; k++) {
            block <<= 1;
            block += (key[k] == '1');
        }
        for (int k = j + 3; k < j + 8; k++) {
            move <<= 1;
            move += (key[k] == '1');
        }
        block += 4;

        for (int k = i; k < i + block; k++) {
            if (s[k] >= 'a' && s[k] <= 'z') {
                result[k] = (s[k] - 'a' - move + alpha) % alpha + 'a';
            }
            else if (s[k] >= 'A' && s[k] <= 'Z') {
                result[k] = (s[k] - 'A' - move + alpha) % alpha + 'A';
            }
        }
        i += block;
        j += 8;
    }

    cout << result;
}

#include <bits/stdc++.h>

using namespace std;

const int alpha = ('z' - 'a' + 1);

int main() {
    string s;
    getline(cin, s);

    mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> block_size(4, 11);
    uniform_int_distribution<int> move_cnt(1, 32);

    int n = s.size(), i = 0;
    string result = s;
    string key;

    while (i < n) {
        int block = block_size(rnd);
        int move = move_cnt(rnd);
        if (block > n - i) {
            block = n - i;
        }
        for (int j = i; j < i + block; j++) {
            if (s[j] >= 'a' && s[j] <= 'z') {
                result[j] = (s[j] - 'a' + move) % alpha + 'a';
            }
            else if (s[j] >= 'A' && s[j] <= 'Z') {
                result[j] = (s[j] - 'A' + move) % alpha + 'A';
            }
        }
        i += block;
        block -= 4;
        for (int j = 2; j >= 0; j--) {
            key.push_back(((block >> j) & 1) + '0');
        }
        for (int j = 4; j >= 0; j--) {
            key.push_back(((move >> j) & 1) + '0');
        }
    }

    cout << result << '\n' << key;
}

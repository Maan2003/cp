#include <bits/stdc++.h>

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char ch[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> ch[i][j];
        }
        int a, b, c, d;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (ch[i][j] == '*') {
                    a = i;
                    b = j;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (ch[i][j] == '*') {
                    {
                        if (i == a && j == b)
                            continue;
                        else {
                            c = i;
                            d = j;
                            break;
                        }
                    }
                }
            }
        }
        if (a == c) {
            ch[n - a - 1][b] = '*';
            ch[n - a - 1][d] = '*';
        } else if (b == d) {
            ch[a][n - 1 - b] = '*';
            ch[c][n - 1 - d] = '*';
        } else {
            ch[c][b] = '*';
            ch[a][d] = '*';
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << ch[i][j];
            cout << endl;
        }
    }
}


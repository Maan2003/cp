#include <bits/stdc++.h>
#define int long long int
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define REP_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define REP3R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define PB push_back
#define SH std::cout <<
#define LN << '\n'
#define RD std::cin >>
#define va std::vector<auto>

using namespace std;
using str = std::string;
typedef std::vector<int> vi;
template <typename _A, typename _B>
using umap = unordered_map<_A, _B>;
template <typename _A>
using uset = unordered_set<_A>;
template <typename T>
using v = vector<T>;
using ii = std::pair<int, int>;
using iii = std::tuple<int, int, int>;

template <typename T>
void RD_VC(v<T> &a, int n) {
    a.resize(n);
    REP (i, n)
        RD(a[i]);
}
/* Dynamic Programming solution to
find length of the
longest common substring */
#include <string.h>

#include <iostream>
using namespace std;

int LCSubStr(str &X, str &Y) {
    int m = X.size();
    int n = Y.size();
    int LCSuff[m + 1][n + 1];
    int result = 0;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;

            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            } else
                LCSuff[i][j] = 0;
        }
    }

    return result;
}

auto solve(str &a, str &b) {
    int s = LCSubStr(a, b);
    return a.size() + b.size() - s;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcases;
    std::cin >> testcases;
    while(testcases--) {
        str a, b;
        cin >> a >> b;
        cout << solve(a, b) << '\n';
    }

    return 0;
}

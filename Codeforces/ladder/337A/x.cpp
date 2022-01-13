#include <bits/stdc++.h>
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
using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using vll = v<ll>;
using ii = std::pair<int, int>;
using iii = std::tuple<int, int, int>;

template <typename T>
void RD_VC(v<T> &a, int n) {
    a.resize(n);
    REP (i, n)
        RD(a[i]);
}

auto solve(int n, int m, int k, v<v<int>> &a) {
    priority_queue<iii, v<iii>, greater<iii>> pq;
    v<vi> b = a;
    REP (i, n) {
        REP (j, m) {
            // this is a wall
            if (a[i][j] == 0) continue;
            a[i][j] = 0;
            if (i + 1 < n) {
                if (a[i + 1][j] != 0) {
                    a[i][j]++;
                }
            }
            if (j + 1 < m) {
                if (a[i][j + 1] != 0) {
                    a[i][j]++;
                }
            }
            if (i - 1 >= 0) {
                if (a[i - 1][j] != 0) {
                    a[i][j]++;
                }
            }

            if (j - 1 >= 0) {
                if (a[i][j - 1] != 0) {
                    a[i][j]++;
                }
            }
            pq.push({a[i][j], i, j});
        }
    }

    while (k > 0) {
        auto [value, second, third] = pq.top();
        pq.pop();
        if (a[second][third] == -1) continue;
        if (second + 1 < n) {
            // not a wall
            if (a[second + 1][third] > 0) {
                a[second + 1][third]--;
                pq.push({a[second + 1][third], second + 1, third});
            }
        }
        if (third + 1 < m) {
            if (a[second][third + 1] > 0) {
                a[second][third + 1]--;
                pq.push({a[second][third + 1], second, third + 1});
            }
        }
        if (second - 1 >= 0) {
            if (a[second - 1][third] > 0) {
                a[second - 1][third]--;
                pq.push({a[second - 1][third], second - 1, third});
            }
        }
        if (third - 1 >= 0) {
            if (a[second][third - 1] > 0) {
                a[second][third - 1]--;
                pq.push({a[second][third - 1], second, third - 1});
            }
        }
        a[second][third] = -1;
        k--;
    }

    REP (i, n) {
        REP (j, m) {
            char sym = a[i][j] == -1 ? 'X' : b[i][j] == 0 ? '#' : '.';
            cout << sym;
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    ll b, c;
    std::cin >> a;
    v<vi> d(a);
    std::cin >> b >> c;
    REP (i, a) {
        char x;
        d[i].resize(b);
        REP (j, b) {
            std::cin >> x;
            d[i][j] = x == '#' ? 0 : 1;
        }
    }
    solve(a, b, c, d);
    return 0;
}

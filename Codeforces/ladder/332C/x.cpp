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

auto solve(vi &a) {
    int n = a.size();
    if (n == 1) {
        cout << -1 << endl;
        return;
    }
    sort(a.begin(), a.end());

    if (n == 2) {
        int diff = a[1] - a[0];
        if(diff == 0) {
            cout << 1 << endl;
            cout << a[0] << endl;
            return;
        }
        if (diff % 2 == 0) {
            cout << 3 << endl;
            cout << a[0] - diff << ' ' << a[0] + diff / 2 << ' ' << a[1] + diff << endl;
        } else {
            cout << 2 << endl;
            cout << a[0] - diff << ' ' << a[1] + diff << endl;
        }
        return;
    }

    int diff = INT_MAX;
    for (int i = 1; i < n; ++i) {
        diff = min(diff, abs(a[i] - a[i - 1]));
    }
    int wrong = 0;
    for (int i = 1; i < n; ++i) {
        if (abs(a[i] - a[i - 1]) != diff) {
            ++wrong;
        }
    }

    if (wrong == 0) {
        if(diff == 0) {
            cout << 1 << endl;
            cout << a[0] << endl;
            return;
        }
        cout << 2 << endl;
        cout << a[0] - diff << ' ' << a[a.size() - 1] + diff << endl;
    } else if (wrong == 1) {
        for (int i = 1; i < n; ++i) {
            int d2 = abs(a[i] - a[i - 1]);
            if (d2 != diff) {
                if (d2 == 2 * diff) {
                    cout << 1 << endl;
                    cout << a[i - 1] + diff << endl;
                    return;
                } else {
                    cout << 0 << endl;
                    return;
                }
            }
        }
    } else {
        cout << 0 << endl;
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    std::cin >> n;
    vi a(n);
    REP (i, n) { std::cin >> a[i]; }
    solve(a);
    return 0;
}

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

int q1(int x, int y) {
    cout << "? " << x + 1 << " " << y << endl;
    cout.flush();
    cin >> x;
    return x;
}

int done(int x) {
    if (x == -1)
        cout << "! " << x << endl;
    else
        cout << "! " << x + 1 << endl;

    cout.flush();
    return 0;
}

void do_it(int n, int offset) {
    if (n == 0 || n == 1) {
        done(offset);
        return;
    }
    int x1 = q1(offset, offset + n / 2);
    int x2 = q1(offset + n / 2, offset + n);
    if (x1 == 0) {
        do_it(n - n / 2, offset + n / 2);
    } else if (x2 == 0) {
        do_it(n / 2, offset);
    } else {
        done(-1);
    }
}

auto solve() {
    int n;
    RD(n);
    if (q1(0, n) > 1) {
        done(-1);
        return;
    }
    do_it(n, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    RD(t);
    while (t--) {
        solve();
    }
    return 0;
}

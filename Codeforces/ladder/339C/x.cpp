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

const std::string YES = "YES";
const std::string NO = "NO";

bool do_it(int diff, int n, v<bool> b, map<tuple<int, int, int>, int> &c, int last) {
    if (n == 0) {
        return true;
    }

    if (diff < 0) {
        return false;
    }

    if (c.find(make_tuple(n, diff, last)) != c.end()) {
        return c[make_tuple(n, diff, last)] != -1;
    }

    for (int i = diff + 1; i <= 10; i++) {
        if (!b[i]) continue;
        // no same weights
        if (i == last) continue;

        if (do_it(i - diff, n - 1, b, c, i)) {
            b[i] = true;
            c[make_tuple(n, diff, last)] = i;
            return true;
        }
    }

    c[make_tuple(n, diff, last)] = -1;
    return false;
}

auto solve(std::string a, ll b) {
    v<bool> bl(11, false);
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '0') {
            bl[i + 1] = false;
        } else {
            bl[i + 1] = true;
        }
    }

    map<tuple<int, int, int>, int> c;
    int last = -1;
    if (do_it(0, b, bl, c, last)) {
        int diff = 0;
        cout << "YES" << endl;
        int last = -1;
        while (b > 0) {
            int next = c[make_tuple(b, diff, last)];
            diff = next - diff;
            cout << next << ' ';
            last = next;
            b--;
        }
        return;
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::string a;
    ll b;
    std::cin >> a >> b;
    solve(a, b);
    return 0;
}

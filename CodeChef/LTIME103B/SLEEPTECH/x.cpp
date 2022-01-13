#include <bits/stdc++.h>

#include <climits>
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
using ll = long long;
using ull = unsigned long long;
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

auto solve(vi &l, vi &r, int a, int b) {
    int rmn = a;
    int rmx = b;
    int ri = 0;

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    int i = 0;
    int j = 0;
    int joy = 0;
    int mx = 0;
    l.push_back(LONG_LONG_MAX);
    r.push_back(LONG_LONG_MAX);
    int last = LONG_LONG_MAX;
    while (i < l.size() && j < r.size()) {
        int ll = l[i];
        int rr = r[j];
        int val = min(rr, ll);

        while (val > rmx) {
            ri++;
            if (ri > b - a) {
                return mx;
            }
            rmn += a + i;
            rmx += b - i;
        }

        if (rr <= ll) {
            joy--;
            j++;
        } else {
            last = ll;
            joy++;
            i++;
        }
        if (last >= rmn || val <= rmx) mx = max(joy, mx);
    }
    return mx;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        vi l(n);
        vi r(n);
        REP (i, n) {
            cin >> l[i] >> r[i];
            r[i]++;
        }
        cout << solve(l, r, a, b) << endl;
    }

    return 0;
}

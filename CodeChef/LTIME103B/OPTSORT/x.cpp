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
using ii = std::pair<int, int>;
using iii = std::tuple<int, int, int>;

template <typename T>
void RD_VC(v<T> &a, int n) {
    a.resize(n);
    REP (i, n)
        RD(a[i]);
}

auto solve(vi &a) {
    v<ii> minmax(a.size());
    int mn = LONG_LONG_MAX, mx = LONG_LONG_MIN;
    for (int i = a.size() - 1; i >= 0; i--) {
        int val = a[i];
        mn = min(mn, val);
        mx = max(mx, val);

        minmax[i] = {mn, mx};
    }

    mn = LONG_LONG_MAX;
    mx = LONG_LONG_MIN;
    bool sorted = true;
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        if (mx <= minmax[i].first) {
            ans += sorted ? 0 : mx - mn;
            mn = LONG_LONG_MAX;
            mx = LONG_LONG_MIN;
            sorted = true;
        }

        int val = a[i];
        if (val < mx) {
            sorted = false;
        }
        mn = min(mn, val);
        mx = max(mx, val);
    }
    ans += sorted ? 0 : mx - mn;
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    std::cin >> a;
    while (a--) {
        int n;
        vi a;
        cin >> n;
        RD_VC(a, n);
        cout << solve(a) << endl;
    }
    return 0;
}

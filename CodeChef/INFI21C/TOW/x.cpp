#include <bits/stdc++.h>
#define int long long
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

void solve(vi &a, vi &b) {
    v<ii> st;
    REP (i, a.size()) { st.push_back({a[i], -i}); }

    sort(st.begin(), st.end());
    sort(b.begin(), b.end());
    vi ans;
    int i = -1;
    bool bigger = false;
    while (!b.empty()) {
        int x = b.back();
        b.pop_back();
        if (st.empty()) {
            ans.push_back(x);
            break;
        }
        auto [y, newi] = st.back();
        newi = -newi;
        st.pop_back();
        if (x < y) {
            cout << "NO" LN;
            return;
        } else if (x > y) {
            bigger = true;
            ans.push_back(x);
            break;
        } else {
            ans.push_back(x);
            i = newi;
        }
        while (!st.empty() && -st.back().second <= i) {
            st.pop_back();
        }
    }

    if (bigger || (st.empty() && !b.empty())) {
        cout << "YES" LN;
        REP (i, b.size()) { cout << b[i] << " "; }
        REP (i, ans.size()) { cout << ans[i] << " "; }
        cout LN;
    } else {
        cout << "NO" LN;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vi a(n), b(m);
        RD_VC(a, n);
        RD_VC(b, m);
        solve(a, b);
    }
    return 0;
}

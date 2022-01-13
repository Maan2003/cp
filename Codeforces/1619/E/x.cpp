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

void solve(vi &a) {
    sort(a.begin(), a.end());
    v<ii> st;
    ll x = 0;
    ll idx = 0;
    ll cost = 0;
    while (x <= a.size()) {
        ll freq = 0;
        while (idx < a.size() && a[idx] == x) {
            ++freq;
            ++idx;
        }
        if (x != 0) {
            if (!st.empty()) {
                auto [val, valfreq] = st.back();
                st.pop_back();
                cost += (x - 1 - val);
                if (valfreq > 1) {
                    st.push_back({val, valfreq - 1});
                }
            } else {
                while (x <= a.size()) {
                    cout << -1 << ' ';
                    x++;
                }
                return;
            }
        }

        cout << cost + freq << ' ';

        if (freq > 0) {
            st.PB({x, freq});
        }
        x++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcases;
    std::cin >> testcases;
    while (testcases--) {
        int n;
        RD(n);
        vi a(n);
        RD_VC(a, n);
        solve(a);
        cout << endl;
    }
    return 0;
}

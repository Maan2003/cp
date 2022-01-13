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

auto solve(str& s, int k) {
    str s2 = s;
    int l = 0;
    int r = k - 1;
    int i = 0;
    while(k > 0) {
        char val;
        if (i % 2 == 1) {
            val = s[r];
            r--;
        } else {
            val = s[l];
            l++;
        }
        i++;
        s2[k - 1] = val;
        k--;
    }
    cout << s2 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    std::cin >> a;
    while(a--) {
        int n, k;
        cin >> n >> k;
        str s;
        cin >> s;
        solve(s, k);
    }
    return 0;
}

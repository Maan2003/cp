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
void RD_VC(v<T>& a, int n) {
    a.resize(n);
    REP (i, n)
        RD(a[i]);
}

bool is_vowel(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }

auto solve(string& p, string& s, char q) {
    int ops = 0;
    REP (i, p.size()) {
        char l = p[i];
        char r = s[i];
        if(l == '?') l = q;
        if(r == '?') r = q;

        if (l == r) continue;
        if (is_vowel(l) ^ is_vowel(r))
            ops++;
        else
            ops += 2;
    }
    return ops;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    std::cin >> a;
    REP (i, a) {
        int n;
        cin >> n;
        string p, s;
        std::cin >> p >> s;
        int mn = INT_MAX;
        for (char c = 'a'; c <= 'z'; c++) {
            int ops = solve(p, s, c);
            mn = min(mn, ops);
        }
        std::cout << mn LN;
    }
    return 0;
}

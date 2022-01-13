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

auto solve(auto a, auto b, auto c, auto d, const std::vector<auto> &e, const std::vector<auto> &f, const std::vector<auto> &g) {
    // TODO: edit here
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto a, b, c, d;
    std::cin >> a >> b;
    std::vector<auto> e(b), f(b), g(b);
    std::cin >> c >> d;
    REP (i, b) { std::cin >> e[i] >> f[i] >> g[i]; }
    auto ans = solve(a, b, c, d, e, f, g);
    // failed to analyze output format
    // TODO: edit here
    std::cout << ans << '\n';
    return 0;
}

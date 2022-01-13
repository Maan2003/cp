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
auto solve(int a, const std::vector<ll> &b, const std::vector<ll> &c, const std::vector<ll> &d, const std::vector<ll> &e, const std::vector<ll> &f) {
    // TODO: edit here
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    std::cin >> a;
    std::vector<ll> b(a), c(a), d(a), e(a), f(a);
    REP (i, a) { std::cin >> b[i] >> c[i] >> d[i] >> e[i] >> f[i]; }
    auto ans = solve(a, b, c, d, e, f);
    REP (i, a) { std::cout << g[i] << '\n'; }
    return 0;
}

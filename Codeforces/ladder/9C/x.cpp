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

ll solve(ll a) {
    ll x = 0;
    int n = 0;
    // go through digits in a in reverse order
    while (a > 0) {
        ll d = a % 10;
        a /= 10;
        if (d == 1) {
            x = (1 << n) | x;
        } else if (d != 0) {
            for (int i = 0; i <= n; i++) {
                x = (1 << i) | x;
            }
        }
        n++;
    }

    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a;
    std::cin >> a;
    auto ans = solve(a);
    std::cout << ans << '\n';
    return 0;
}

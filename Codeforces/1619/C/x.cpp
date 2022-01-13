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

auto solve(ll n, ll s) {
    ll ten_pow = 1;
    ll ans = 0;
    while (true) {
        if (n == 0 && s == 0) {
            return ans;
        }
        if (s == 0 && n != 0) {
            return (ll)-1;
        }
        if (s % 10 >= n % 10) {
            ll s1 = s % 10;
            ll n1 = n % 10;
            ans = ans + (s1 - n1) * ten_pow;
            s /= 10;
            n /= 10;
        } else {
            ll s1 = s % 100;
            ll n1 = n % 10;
            if (s1 - n1 > 9 || s1 - n1 < 0) {
                return (ll)-1;
            }
            ans = ans + (s1 - n1) * ten_pow;
            s /= 100;
            n /= 10;
        }
        ten_pow *= 10;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcases;
    std::cin >> testcases;
    while (testcases--) {
        ll n, s;
        cin >> n >> s;
        ll r = solve(n, s);
        if (r == 0) r = -1;
        cout << r << endl;
    }
    return 0;
}

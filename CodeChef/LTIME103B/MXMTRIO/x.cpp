#include <bits/stdc++.h>

#include <random>
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

signed main() {
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 1000);
    for (int i = 0; true; i++) {
        int a = uniform_dist(e1);
        int b = uniform_dist(e1);
        int c = uniform_dist(e1);
        int m1 = max(a, max(b, c));
        int m2 = min(max(a, c), min(max(b, c), max(a, b)));
        int m0 = min(a, min(b, c));
        if ((m1 - m0) * m2 < (m2 - m0) * m1) {
            cout << a << " " << b << " " << c << endl;
        }
        if (i % 1000000 == 0) {
            cout << i << '\n';
        }
    }

    return 0;
}

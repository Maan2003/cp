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

int solve(int n) {
    int max = 0;
    int max_val = n;
    for (int i = 2; i * i <= n; i++) {
        int cnt = 0;
        int tmp = n;
        while (tmp % i == 0) {
            cnt++;
            tmp /= i;
        }
        if (max < cnt) {
            max = cnt;
            max_val = i;
        }
    }
    return max_val;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<ll> a(n);
    REP (i, n) {
        int x;
        cin >> x;
        cout << solve(x) << endl;
    }
    return 0;
}

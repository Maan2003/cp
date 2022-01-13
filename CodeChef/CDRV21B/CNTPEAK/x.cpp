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

int do_it(vi a, int n, int i) {
    int cnt = 0;
    if (i == n) {
        for (int j = 1; j < n - 1; j++) {
            if (a[j] > a[j - 1] && a[j] > a[j + 1]) {
                cnt++;
            } else if (a[j] < a[j - 1] && a[j] < a[j + 1]) {
                cnt++;
            }
        }
        return cnt;
    }
    REP (x, 3) {
        a[i] = x;
        cnt += do_it(a, n, i + 1);
    }
    return cnt;
}

int solve(int n) {
    vi a(n);
    return do_it(a, n, 0);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    std::cin >> n;
    int ans[] = {0, 0, 10, 60, 270, 1080, 4050, 14580, 51030, 174960};
    REP (i, n) {
        int x;
        std::cin >> x;
        cout << ans[x - 1] << endl;
    }
    return 0;
}

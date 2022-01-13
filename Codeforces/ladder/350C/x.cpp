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
#define endl '\n'

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

auto solve(v<ii> &a) {
    sort(a.begin(), a.end(), [](const ii &a, const ii &b) {
        int first = abs(a.first) - abs(b.first);
        if (first != 0) return first < 0;
        return abs(a.second) < abs(b.second);
    });

    v<tuple<int, int, char>> ans;
    // takes 6 instructions per element
    ans.reserve(a.size() * 6);
    for (auto &p : a) {
        char dir1 = p.first < 0 ? 'L' : 'R';
        char dir2 = p.second < 0 ? 'D' : 'U';
        char dir3 = p.first < 0 ? 'R' : 'L';
        char dir4 = p.second < 0 ? 'U' : 'D';
        if (p.first != 0) {
            ans.push_back({1, abs(p.first), dir1});
        }
        if (p.second != 0) {
            ans.push_back({1, abs(p.second), dir2});
        }
        ans.push_back({2, 0, '\0'});
        if (p.first != 0) {
            ans.push_back({1, abs(p.first), dir3});
        }
        if (p.second != 0) {
            ans.push_back({1, abs(p.second), dir4});
        }
        ans.push_back({3, 0, '\0'});
    }
    cout << ans.size() LN;
    for (auto &p : ans) {
        auto [a, b, c] = p;
        if (a == 1) {
            cout << a << ' ' << b << ' ' << c << endl;
        } else {
            cout << a << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    std::cin >> n;
    v<ii> a(n);
    REP (i, n) {
        int x, y;
        std::cin >> x >> y;
        a[i] = {x, y};
    }
    solve(a);
    return 0;
}

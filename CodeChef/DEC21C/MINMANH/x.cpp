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
typedef std::vector<int> vi;
template <typename _A, typename _B>
using umap = unordered_map<_A, _B>;
template <typename T>
using v = vector<T>;

int solve(vi &a, vi &b) {
    // TODO: edit here
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int m, n;
    cin >> n >> m;

    vi s, t;

    REP(_, n) {
        int x;
        cin >> x;
        s.PB(x);
    }

    REP(_, m) {
        int x;
        cin >> x;
        t.PB(x);
    }
    return 0;
}

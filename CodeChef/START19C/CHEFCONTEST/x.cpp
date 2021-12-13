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

template <typename T>
void RD_VC(v<T> &a, int n) {}

auto solve(int x, int y, int p, int q) {
    int v1 = x + p * 10;
    int v2 = y + q * 10;
    if (v1 == v2) {
        cout << "Draw" << endl;
    } else if (v1 > v2) {
        cout << "Chefina" << endl;
    } else {
        cout << "Chef" << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // failed to analyze input format
    // TODO: edit here
    int n;
    std::cin >> n;
    std::vector<int64_t> a(n);
    int x, y, p, q;
    REP (i, n) { 
        cin >> x >> y >> p >> q;
        solve(x, y, p, q);
    }
    return 0;
}

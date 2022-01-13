#include <bits/stdc++.h>

#include <algorithm>
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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int testcases;
    std::cin >> testcases;
    REP (_, testcases) {
        uint32_t w, h;
        cin >> w >> h;

        vi x(32, 0);

        for (int i = w; i <= h; i++) {
            uint32_t j = i;
            for (int b = 0; b < 32; b++) {
                if (j & 1) x[b]++;
                j = j >> 1;
            }
        }

        int val = *std::max_element(x.begin(), x.end());
        int cnt = h - w + 1;
        cout << cnt - val << "\n";
    }
    return 0;
}

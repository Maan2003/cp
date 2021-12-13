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
template <typename _A, typename _B> using umap = unordered_map<_A, _B>;
template <typename T> using v = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using mpq = priority_queue<T, v<T>, greater<T>>;
using pi = pair<int, int>;
template <typename T, typename U> using p = pair<T, U>;

int trap(vi &hs) {
  vi maxl;
  vi maxr;

  int mx = 0;
  // 0 1 1 0
  REP(i, hs.size()) {
    maxl.PB(mx);
    mx = max(mx, hs[i]);
  }
  mx = 0;
  REP_R(i, hs.size()) {
    maxr.PB(mx);
    mx = max(mx, hs[i]);
  }

  int sum = 0;
  REP(i, hs.size())
    sum += max(0, min(maxl[i], maxr[hs.size() - i - 1]) - hs[i]);

  return sum;
}

int main() {
  vi vi{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << trap(vi) << endl;
}

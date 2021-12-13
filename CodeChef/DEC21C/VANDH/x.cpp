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

int out[100000];

auto solve(int hills, int val) {
  if (hills == val) {
    int j = 0;
    for (int i = 0; i < hills + 1; i++) {
      out[j++] = 0;
      out[j++] = 1;
    }
    cout << j LN;
    REP(i, j) { cout << out[i]; }
  } else if (hills < val) {
    int j = 0;
    // 1 will be covered by not adding 0 at start
    int rem = val - hills - 1;

    for (int i = 0; i < val + 1; i++) {
      out[j++] = 0;
      out[j++] = 1;
      if (i != 0 && rem > 0) {
        // add 1 to reduce number of hills
        out[j++] = 1;
        rem--;
      }
    }
    // j - 1 to no include first 0
    cout << j - 1 LN;
    REP3(i, 1, j) { cout << out[i]; }
  } else {
    int j = 0;
    // 1 will be covered by not adding 1 at end
    int rem = hills - val - 1;

    for (int i = 0; i < hills + 1; i++) {
      out[j++] = 0;
      out[j++] = 1;
      if (i != val && rem > 0) {
        // add 0 to reduce number of valleys
        out[j++] = 0;
        rem--;
      }
    }
    // j - 1 to no include first 0
    cout << j - 1 LN;
    REP3(i, 0, j - 1) { cout << out[i]; }
  }
  cout << endl;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int64_t> a(n), b(n);
  REP(i, n) {
    std::cin >> a[i] >> b[i];
    solve(a[i], b[i]);
  }
  return 0;
}

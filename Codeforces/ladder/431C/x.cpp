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

template <typename T> void RD_VC(v<T> &a, int n) {}

constexpr int64_t MOD = 1000000007;
int64_t dp[1000][1000][2];

int64_t do_it(int s, int k, int d) {
  if (s == 0)
    return d == 0 ? 1 : 0;

  if (s < 0)
    return 0;

  int dd = d == 0 ? 1 : 0;

  if (dp[s][k][dd] != -1)
    return dp[s][k][dd];

  dp[s][k][dd] = 0;
  for (int i = 1; i <= k; ++i) {
    if (i >= d) {
      dp[s][k][dd] += do_it(s - i, k, 0);
    } else {
      dp[s][k][dd] += do_it(s - i, k, d);
    }
    dp[s][k][dd] %= MOD;
  }

  return dp[s][k][dd];
}

int64_t solve(int64_t a, int64_t b, int64_t c) {
  memset(dp, -1, sizeof(dp));
  int64_t ways = do_it(a, b, c);
  return ways;
}

// generated by oj-template v4.8.1
// (https://github.com/online-judge-tools/template-generator)
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int64_t a, b, c;
  std::cin >> a >> b >> c;
  auto ans = solve(a, b, c);
  std::cout << ans << '\n';
  return 0;
}
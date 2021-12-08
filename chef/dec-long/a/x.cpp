#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define REP_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define REP3R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;

char comp[3];
char solve(char x, char y) {
  char *xi = find(ALL(comp), x);
  char *yi = find(ALL(comp), y);
  if (xi > yi)
    return y;
  else
    return x;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  REP(_, t) {
    char a, b, c, x, y;
    std::cin >> comp[0] >> comp[1] >> comp[2] >> x >> y;
    std::cout << solve(x, y) << std::endl;
  }
  return 0;
}

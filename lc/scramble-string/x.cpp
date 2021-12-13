#include <bits/stdc++.h>
#include <unordered_set>
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
template <typename _A, typename _B> using ummap = unordered_multimap<_A, _B>;
template <typename _A> using uset = unordered_set<_A>;
template <typename _A> using umset = unordered_multiset<_A>;
template <typename T> using v = vector<T>;
using i8 = int8_t;
using u8 = uint8_t;
int level;
bool solve_in_rev(string &s1, string &s2, int x, int y, int l);

int cache[100][100][100] = {-1};

// TODO: this is pure, so should we cache?
// precondition: s1[x..x+l] and s2[y..y+l] must have same characters
bool solve(string &s1, string &s2, int x, int y, int l) {
  if (l == 0)
    return true;

  if (l == 1)
    return s1[x] == s2[y];

  if (cache[x][y][l] != -1)
    return cache[x][y][l];

  REP(i, level) { cerr << " "; }
  cerr << "solve(" << x << ", " << y << ", " << l << ")\n";

  i8 chars[26] = {0};

  auto any_non_zero = [&]() {
    for (auto &c : chars)
      if (c != 0)
        return true;
    return false;
  };

  for (int i = 0; i < l; i++) {
    int s1c = s1[x + i] - 'a';
    int s2c = s2[y + i] - 'a';

    chars[s1c]++;
    chars[s2c]--;

    // great   rgeat
    // characters in left match
    // so characters in right must also match
    if (!any_non_zero()) {
      if (i == l - 1)
        continue;
      level++;
      // check first i characters
      if (solve(s1, s2, x, y, i + 1) &&
          solve(s1, s2, x + i + 1, y + i + 1, l - i - 1)) {
        level--;
        return cache[x][y][l] = 1;
      }
      level--;
    }
  }
  level++;
  bool ans = solve_in_rev(s1, s2, x, y, l);
  level--;
  return cache[x][y][l] = ans;
}

bool solve_in_rev(string &s1, string &s2, int x, int y, int l) {
  REP(i, level) { cerr << " "; }
  cerr << "solve_in_rev(" << x << ", " << y << ", " << l << ")\n";
  i8 chars[26] = {0};
  auto any_non_zero = [&]() {
    for (auto &c : chars)
      if (c != 0)
        return true;
    return false;
  };

  for (int i = 0; i < l; i++) {
    int s1c = s1[x + l - i - 1] - 'a';
    int s2c = s2[y + i] - 'a';

    chars[s1c]++;
    chars[s2c]--;

    // eatrg    great
    // characters in left match
    // so characters in right must also match
    if (!any_non_zero()) {
      if (i == l - 1)
        continue;

      level++;
      // check first i characters
      if (solve(s1, s2, x + l - i - 1, y, i + 1) &&
          solve(s1, s2, x, y + i + 1, l - i - 1)) {
        level--;
        return true;
      }
    }
  }
  return false;
}

int main() {
  string s1, s2;
  cin >> s1;
  cin >> s2;
  REP(i, 100) {
    REP(j, 100) {
      REP(k, 100) { cache[i][j][k] = -1; }
    }
  }
  cout << (solve(s1, s2, 0, 0, s1.size()) ? "Yes" : "NO");
}

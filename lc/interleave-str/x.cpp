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

bool solve(string &s1, string &s2, string &s3, int i, int j) {
  if (i == s1.size() && j == s2.size()) {
    return true;
  }
  // one of them reached the end
  if(i == s1.size() || j == s2.size()) {
    return false;
  }
}

bool solve(string &s1, string &s2, string &s3) {
  return solve(s1, s2, s3, 0, 0);
}

int main() {
  string s1, s2, s3;
  cin >> s1;
  cin >> s2;
  cin >> s3;
  cout << solve(s1, s2, s3) << endl;
}

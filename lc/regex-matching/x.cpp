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

enum syn {
  repeat_any,
  repeat_char,
  literal,
};

bool solve(string s, string p) {
  // TODO
}

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

// (https://github.com/online-judge-tools/template-generator)
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  // failed to analyze input format
  // TODO: edit here
  int n;
  std::cin >> n;

  while (n--) {
    vi x(7);
    REP(i, 7) { cin >> x[i]; }
    cout << x[0] << ' ' << x[1] << ' ';
    bool found = false;
    if(x[2] == x[0] + x[1]) {
        cout << x[3];
    } else {
        cout << x[2];
    }
    cout << endl;
  }
  return 0;
}

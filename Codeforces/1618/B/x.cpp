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

// generated by oj-template v4.8.1
// (https://github.com/online-judge-tools/template-generator)
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> a(n - 2);
    REP(i, n - 2) cin >> a[i];
    bool found = false;
    REP(i, n - 3) {
      if (a[i][1] == a[i + 1][0]) {
        cout << a[i][0];
      } else {
        found = true;
        cout << a[i];
      }
    }
    cout << a[n - 3];
    if (!found) {
      cout << 'a';
    }

    cout << endl;
  }
  return 0;
}

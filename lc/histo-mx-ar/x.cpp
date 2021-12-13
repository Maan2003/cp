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
#define loop while (1)

using namespace std;
typedef std::vector<int> vi;
template <typename _A, typename _B> using umap = unordered_map<_A, _B>;
template <typename T> using v = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using mpq = priority_queue<T, v<T>, greater<T>>;
using pi = pair<int, int>;
template <typename T, typename U> using p = pair<T, U>;

int nsml[10000]; // next smaller elem
int psml[10000]; // prev smaller elem

void c1(vi &hs) {
  int i = 0;
  stack<int> st;
  loop {
    // we reached the end
    if (i == hs.size())
      return;
    if (!st.empty() && hs[st.top()] > hs[i]) {
      nsml[st.top()] = i;
      st.pop();
    } else {
      st.push(i);
      i++;
    }
  }
}

void c2(vi &hs) {
  int i = hs.size() - 1;
  stack<int> st;
  loop {
    // we reached the end
    if (i < 0)
      return;
    if (!st.empty() && hs[st.top()] > hs[i]) {
      psml[st.top()] = i;
      st.pop();
    } else {
      st.push(i);
      i--;
    }
  }
}

int solve(vi &hs) {
  REP(i, hs.size()) {
    nsml[i] = hs.size();
    psml[i] = -1;
  }
  c1(hs);
  c2(hs);
  int mx = 0;
  REP(i, hs.size()) {
    int area = (nsml[i] - psml[i] - 1) * hs[i];
    mx = max(mx, area);
  }
  return mx;
}

int main() {
  vi v{4, 2, 0, 3, 2, 4, 3, 4};
  cout << solve(v);
}

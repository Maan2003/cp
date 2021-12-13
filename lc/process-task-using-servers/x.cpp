#include <bits/stdc++.h>
#include <queue>
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

vi solve(vi &servers, vi &tasks) {
  // weight and server id
  mpq<pi> sq;

  // end time, server idx
  mpq<pi> tq;

  vi ans;

  for (int i = 0; i < servers.size(); i++) {
    sq.push(p<int, int>(servers[i], i));
  }

  int t = 0;

  for (int tid = 0; tid < tasks.size(); tid++) {
    while (tid > t) t++;

    while (!tq.empty()) {
      pi free_server = tq.top();
      if (free_server.first == t) {
        tq.pop();
        sq.push({servers[free_server.second], free_server.second});
      } else if (sq.empty()) {
        tq.pop();
        sq.push({servers[free_server.second], free_server.second});
        t = free_server.first;
      } else break;
    }
    pi selected = sq.top();
    sq.pop();
    ans.PB(selected.second);
    tq.push({t + tasks[tid], selected.second});
  }

  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int sn, x, tn;
  vector<int> s;
  vector<int> t;

  RD sn;
  REP(i, sn) {
    RD x;
    s.PB(x);
  }

  RD tn;
  REP(i, tn) {
    RD x;
    t.PB(x);
  }

  vi ans = solve(s, t);
  for (int i = 0; i < ans.size(); i++) {
    SH ans[i] << " ";
  }
  SH endl;
}

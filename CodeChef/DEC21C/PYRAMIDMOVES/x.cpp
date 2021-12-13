#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
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
using ll = uintmax_t;
ll MOD = 1e9 + 7;

int tn;
int t[100000];

void gen_table(int n) {
  int i = 1;
  int j = 1;
  tn = 0;
  while (i <= n) {
    t[tn++] = i;
    i += j;
    j++;
  }
}

// level, offset
using pos = pair<int, int>;
// finds the level and offset of the element
pos find_pos(int n) {
  int level = upper_bound(t, t + tn, n) - 1 - t;
  return {level, n - t[level]};
}

/* Iterative Function to calculate (x^y)%p
in O(log y) */
unsigned long long power(unsigned long long x, int y, int p) {
  unsigned long long res = 1; // Initialize result

  x = x % p; // Update x if it is more than or
  // equal to p

  while (y > 0) {

    // If y is odd, multiply x with result
    if (y & 1)
      res = (res * x) % p;

    // y must be even now
    y = y >> 1; // y = y/2
    x = (x * x) % p;
  }
  return res;
}

// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, int p) {
  return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
unsigned long long NCR(unsigned long long n, int r, int p) {
  // If n<r, then nCr should return 0
  if (n < r)
    return 0;
  // Base case
  if (r == 0)
    return 1;

  // Fill factorial array so that we
  // can find all factorial of r, n
  // and n-r
  unsigned long long fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++)
    fac[i] = (fac[i - 1] * i) % p;

  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}

ll solve(int start, int end) {
  auto s = find_pos(start);
  auto e = find_pos(end);
  int v = e.first - s.first;
  int h = e.second - s.second;
  if (v < 0 || h < 0)
    return 0;
  return NCR(v, h, MOD);
}

int main() {
  gen_table(2e9);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  int a, b;
  REP(i, n) {
    RD a;
    RD b;
    SH solve(a, b) LN;
  }
  return 0;
}

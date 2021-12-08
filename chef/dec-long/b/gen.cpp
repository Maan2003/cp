#include <bits/stdc++.h>
#include <unordered_map>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define REP_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define REP3R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define ALL(x) ::std::begin(x), ::std::end(x)
#define PB push_back
#define SH std::cout <<
#define LN << '\n'
#define SPC << ' '
#define RD std::cin >>
#define va std::vector<auto>

using namespace std;
typedef std::vector<int> vi;
template <typename _A, typename _B> using umap = unordered_map<_A, _B>;
template <typename T> using v = vector<T>;


int main() {
    // create a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    // generate a random number between 1 and 100000
    int t = 1;
    SH t LN;
    REP(_, t) {
        // number between 1 and 2 * 10^5

        std::uniform_int_distribution<> dis2(1, 1000);
        int n = dis2(gen);
        SH n LN;
        REP(_, n) {
            std::uniform_int_distribution<> dis3(1, n);
            int x = dis3(gen);
            SH x SPC;
        }
        SH endl;
    }

}

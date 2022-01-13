#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define REP_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define REP3R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define va std::vector<auto>

using namespace std;
using str = std::string;
using ld = long double;
using ii = std::pair<int, int>;
using iii = std::tuple<int, int, int>;

template <typename T>
using v = vector<T>;

using vi = vector<int>;
using vvi = vector<vector<int>>;

template <typename _A, typename _B>
using umap = unordered_map<_A, _B>;
template <typename _A>
using uset = unordered_set<_A>;

bool solve(v<vi>& a, int w, int h) {
    int n = a.size();
    int m = a[0].size();
    v<v<ii>> sizes;
    sizes.resize(n);
    REP (i, n) {
        sizes[i] = v<ii>();
        sizes[i].resize(m);
    }

    REP (i, n) {
        int j = 0;
        while (j < m) {
            int r = j;
            while (r < m && a[i][r] == 0) r++;
            for (int l = j; l < r; l++) {
                int ls = l - j;
                int rs = r - l;
                sizes[i][l] = {ls, rs};
                // found an empty tile where a stamp can never be placed
                if (ls + rs < w) return false;
            }
            j = r + 1;
        }
    }

    REP (i, m) {
        int j = 0;
        while (j < n) {
            int r = j;
            while (r < n && a[r][i] == 0) r++;
            for (int l = j; l < r; l++) {
                int ls = l - j;
                int rs = r - l;
                sizes[l][i] = {ls, rs};
                // found an empty tile where a stamp can never be placed
                if (ls + rs < w) return false;
            }
            j = r + 1;
        }
    }

    /*
    vi before;
    before.resize(n);
    vi after;
    after.resize(n);
    REP (j, m) {
        before[0] = 0;
        for (int i = 1; i < n; i++) {
            if (sizes[i][j].first >= sizes[i - 1][j].first && sizes[i][j].second >= sizes[i - 1][j].second) {
                before[i] = before[i - 1] + 1;
            } else {
                before[i] = 0;
            }
        }

        after[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (sizes[i][j].first >= sizes[i + 1][j].first && sizes[i][j].second >= sizes[i + 1][j].second) {
                after[i] = after[i + 1] + 1;
            } else {
                after[i] = 1;
            }
        }

        REP (i, n) {
            if (a[i][j] == 0 && before[i] + after[i] < h) {
                return false;
            }
        }
    }
    */
    return true;
}

#undef int
#undef va

template <typename T>
void RD_VC(v<T>& a, int n) {
    a.resize(n);
    REP (i, n)
        cin >> a[i];
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    v<vi> a;
    a.resize(n);
    REP (i, n) {
        a[i] = vi();
        a[i].resize(m);
        REP (j, m) { cin >> a[i][j]; }
    }
    int sw, sh;
    cin >> sh >> sw;
    cout << (solve(a, sw, sh) ? "YES" : "NO") << endl;
    return 0;
}

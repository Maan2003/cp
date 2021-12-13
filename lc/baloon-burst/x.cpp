#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>> &segments) {
  vector<pair<int, int>> input;

  for (int i = 0; i < segments.size(); i++) {
    input.push_back({i, 1});
    input.push_back({i, 0});
  }

  auto get_value = [&](const pair<int, int> &p) {
    if (p.second == 1) {
      return segments[p.first][0];
    } else {
      return segments[p.first][1];
    }
  };

  sort(input.begin(), input.end(), [&](const auto &a, const auto &b) {
    int v1 = get_value(a);
    int v2 = get_value(b);
    if (v1 != v2)
      return v1 < v2;
    else
      return a.second >= b.second;
  });

  int count = 0;
  unordered_set<int> active;
  for (auto &p : input) {
    if (p.second == 1) { // start
      active.insert(p.first);
    } else if (active.find(p.first) != active.end()) { // end
      // we have statified all the active segments
      // remove all
      active.clear();
      count++;
    } else { // end
      // the segment are already statisfied
      // do nothing
    }
  }

  return count;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> segments(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    segments[i] = {a, b};
  }

  cout << solve(segments) << endl;
  return 0;
}

#include <bits/stdc++.h>
#include <vector>

using namespace std;

int dp[2 * 10000] = {-1};
class Solution {
public:
  static int solve(vector<int> &nums, int start) {
    int s = start;
    if (start >= nums.size())
      return 0;
    if (dp[s] != -1)
      return dp[s];

    int ans = 0;
    int pts = 0;
    int val = nums[start];
    while (nums[start] == val) {
      pts += val;
      start++;
      // feels Out of bounds man
      if (start == nums.size()) {
        return dp[s] = pts;
      }
    }

    int start2 = start;
    int val2 = nums[start];
    if (val2 == val + 1) {
      // lets delete the number
      while (nums[start] == val2) {
        start++;
      }
      return dp[s] = max(pts + solve(nums, start), solve(nums, start2));

    } else {
      // no need to delete
      return dp[s] = pts + solve(nums, start2);
    }
  }
  static int deleteAndEarn(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++)
      dp[i] = -1;
    sort(nums.begin(), nums.end());
    return solve(nums, 0);
  }
};

int main() {
  int n, x;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    cin >> x;
    nums.push_back(x);
  }
  int sol = Solution::deleteAndEarn(nums);
  cout << sol << endl;
}

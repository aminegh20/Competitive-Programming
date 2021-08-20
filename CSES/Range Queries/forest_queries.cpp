#include <bits/stdc++.h>
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  } 
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < n + 1; ++j) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (a[i - 1][j - 1] == '*');
    }
  }
  while (q--) {
    int x, y, xx, yy;
    cin >> x >> y >> xx >> yy;
    cout << dp[xx][yy] - dp[xx][y - 1] - dp[x - 1][yy] + dp[x - 1][y - 1] << '\n';
  }
  return 0;
}
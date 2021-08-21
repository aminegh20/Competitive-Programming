#include <bits/stdc++.h>
using namespace std;

constexpr long long inf = (long long) 1e18;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<long long>> g(n, vector<long long>(n, inf));
  for (int i = 0; i < m; i++) {
    int a, b;
    long long c;
    cin >> a >> b >> c;
    a--, b--;
    g[a][b] = g[b][a] = min(g[a][b], c);
  }
  for (int i = 0; i < n; i++) {
    g[i][i] = 0;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
  while (q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    long long ans = g[a][b];
    cout << (ans == inf ? -1 : ans) << '\n';
  }
  return 0;
}
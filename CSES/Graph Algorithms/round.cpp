#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  } 
  int beg = -1;
  int end = -1;
  vector<bool> was(n, false);
  vector<int> parent(n, -1);
  function<void(int, int)> Dfs = [&](int u, int pr) -> void {
    was[u] = true;
    for (int v : g[u]) {
      if (v == pr) {
        continue;
      }
      if (was[v]) {
        beg = u;
        end = v;
        return;
      }
      parent[v] = u;
      Dfs(v, u);
    }
  };
  vector<int> cycle;
  for (int i = 0; i < n; i++) {
    if (was[i] == false) {
      Dfs(i, -1);
      if (beg != -1) {
        cycle.emplace_back(beg);
        int node = end;
        while (node != beg) {
          cycle.emplace_back(node);
          node = parent[node];
        }
        cycle.emplace_back(beg);
        reverse(cycle.begin(), cycle.end());
        break;
      }
    }
  }
  if (cycle.empty()) {
    cout << "IMPOSSIBLE" << '\n';
    return 0;
  }
  cout << cycle.size() << '\n';
  for (int u : cycle) {
    cout << u + 1 << " ";
  }
  cout << '\n';
  return 0;
}
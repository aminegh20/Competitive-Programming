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
  constexpr int inf = (int) 1e9;
  vector<int> dist(n, inf);
  vector<int> pr(n);
  pr[0] = -1;
  dist[0] = 0;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (dist[v] == inf) {
        dist[v] = dist[u] + 1;
        pr[v] = u;
        q.push(v);
      }
    }
  }
  if (dist[n - 1] == inf) {
    cout << "IMPOSSIBLE" << '\n';
    return 0;
  }
  vector<int> path;
  int node = n - 1;
  while (pr[node] != -1) {
    path.push_back(node);
    node = pr[node];
  }
  path.push_back(0);
  reverse(path.begin(), path.end());
  cout << path.size() << '\n';
  for (int u : path) {
    cout << u + 1 << " ";
  }
  cout << '\n';
  return 0;
}
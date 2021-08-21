#include <bits/stdc++.h>
using namespace std;
 
constexpr int inf = (int) 1e9;
 
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
  bool ok = true;
  vector<int> dist(n, inf);
  vector<int> flag(n, -1);
  for (int i = 0; i < n; i++) {
    if (dist[i] == inf) {
      dist[i] = 0;
      flag[i] = 0;
      queue<int> q;
      q.push(i);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
          if (dist[v] == inf) {
            dist[v] = dist[u] + 1;
            flag[v] = flag[u] ^ 1;
            q.push(v);
          } else {
            if (flag[v] == flag[u]) {
              ok = false;
              break;
            }
          }
        }
      }
      if (!ok) {
        break;
      }
    }
  }
  if (!ok) {
    cout << "IMPOSSIBLE" << '\n';
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cout << flag[i] + 1 <<  " ";
  }
  cout << '\n';
  return 0;
}
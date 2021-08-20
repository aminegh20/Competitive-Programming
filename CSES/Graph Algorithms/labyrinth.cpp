#include <bits/stdc++.h>
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  } 
  vector<vector<int>> g(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] != '#') {
        if (i + 1 < n && a[i + 1][j] != '#') {
          int a = i * m + j;
          int b = i * m + j + m;
          g[a].push_back(b);
          g[b].push_back(a);
        }
        if (j + 1 < m && a[i][j + 1] != '#') {
          int a = i * m + j;
          int b = i * m + j + 1;
          g[a].push_back(b);
          g[b].push_back(a);
        }
      }
    }
  }
  vector<pair<int, int>> id(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      id[i * m + j] = make_pair(i, j);
    }
  }
  int beg = 0;
  int end = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'A') beg = i * m + j;
      if (a[i][j] == 'B') end = i * m + j;
    }
  }
  constexpr int inf = (int) 1e9;
  vector<int> dist(n * m, inf);
  vector<int> prnt(n * m );
  queue<int> q;
  q.push(beg);
  dist[beg] = 0;
  prnt[beg] = -1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (dist[v] == inf) {
        dist[v] = dist[u] + 1;
        prnt[v] = u;
        q.push(v);
      }
    }
  }
  if (dist[end] == inf) {
    cout << "NO" << '\n';
    return 0;
  }
  vector<pair<int, int>> path;
  int node = end;
  while (prnt[node] != -1) {
    path.push_back(id[node]);
    node = prnt[node];
  }
  reverse(path.begin(), path.end());
  cout << "YES" << '\n';
  cout << dist[end] << '\n';
  auto pr = id[beg];
  for (auto [x, y] : path) {
    if (pr.first == x + 1) cout << 'U';
    if (pr.first == x - 1) cout << 'D';
    if (pr.second == y + 1) cout << 'L';
    if (pr.second == y - 1) cout << 'R';
    pr = make_pair(x, y);
  }
  return 0;
}
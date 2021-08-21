#include <bits/stdc++.h>
using namespace std;

constexpr int inf = (int) 1e9;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  } 
  vector<vector<int>> g(n * m + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] != '#') {
        if (i + 1 < n && a[i + 1][j] != '#') {
          g[i * m + j].push_back(i * m + m + j);
          g[i * m + m + j].push_back(i * m + j);
        }
        if (j + 1 < m && a[i][j + 1] != '#') {
          g[i * m + j].push_back(i * m + j + 1);
          g[i * m + j + 1].push_back(i * m + j);
        }
      }
    }
  }
  vector<pair<int, int>> id(n * m + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      id[i * m + j] = make_pair(i, j);
    }
  }
  id[n * m] = make_pair(-1, -1);
  vector<int> avoid(n * m + 1, inf);
  queue<int> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'M') {
        q.push(i * m + j);
        avoid[i * m + j] = 0;
      }
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (avoid[v] == inf) {
        avoid[v] = avoid[u] + 1;
        q.push(v);
      }
    }
  }
  avoid[n * m] = inf;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] != '#') {
        if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
          g[n * m].push_back(i * m + j);
          g[i * m + j].push_back(n * m);
        }
      }
    }
  }
  int beg = 0;
  int end = n * m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'A') {
        beg = i * m + j;
      }
    }
  }
  vector<int> dist(n * m + 1, inf);
  vector<int> prnt(n * m + 1);
  q.push(beg);
  dist[beg] = 0;
  prnt[beg] = -1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (dist[v] == inf) {
        int que = dist[u] + 1;
        if (que < avoid[v]) {
          dist[v] = que;
          prnt[v] = u;
          q.push(v);
        }
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
  path.pop_back();
  cout << "YES" << '\n';
  cout << dist[end] - 1 << '\n';
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
#include <bits/stdc++.h>
using namespace std;
 
class matching {
  public:
  std::vector<std::vector<int>> g;
  std::vector<int> pa;
  std::vector<int> pb;
  std::vector<int> was;
  int n, m;
  int res;
  int iter;
 
  matching(int _n, int _m) : n(_n), m(_m) {
    assert(0 <= n && 0 <= m);
    pa = std::vector<int>(n, -1);
    pb = std::vector<int>(m, -1);
    was = std::vector<int>(n, 0);
    g.resize(n);
    res = 0;
    iter = 0;
  }
 
  void add(int from, int to) {
    assert(0 <= from && from < n && 0 <= to && to < m);
    g[from].push_back(to);
  }
 
  private:
  bool dfs(int v) {
    was[v] = iter;
    for (int u : g[v]) {
      if (pb[u] == -1) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    for (int u : g[v]) {
      if (was[pb[u]] != iter && dfs(pb[u])) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    return false;
  }
 
  public:
  int solve() {
    while (true) {
      iter++;
      int add = 0;
      for (int i = 0; i < n; i++) {
        if (pa[i] == -1 && dfs(i)) {
          add++;
        }
      }
      if (add == 0) {
        break;
      }
      res += add;
    }
    return res;
  }
 
  int run_one(int v) {
    if (pa[v] != -1) {
      return 0;
    }
    iter++;
    return (int) dfs(v);
  }
};
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> depth(n);
  function<void(int, int)> Dfs = [&](int u, int pr) -> void {
    if (pr == -1) {
      depth[u] = 0;
    }
    for (int v : g[u]) {
      if (v == pr) {
        continue;
      }
      if (pr != -1) {
        depth[v] = (depth[u] + 1) % 2;
      }
    }
  };
  Dfs(0, -1);
  matching mat(n, n);
  for (int i = 0; i < n; ++i) {
    for (int v : g[i]) {
      int from = (depth[i] & 1 ? v : i);
      int to = (depth[i] & 1 ? i : v);
      mat.add(from, to);
    }
  }
  int ans = mat.solve();
  cout << ans / 2 << '\n';
  return 0;
}
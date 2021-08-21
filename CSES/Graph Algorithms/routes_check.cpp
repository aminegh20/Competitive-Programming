#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph {
  public:
  struct edge {
    int from;
    int to;
    T cost;
  };

  std::vector<edge> edges;
  std::vector<std::vector<int>> g;
  int n;

  graph(int _n) : n(_n) {
    g.resize(n);
  }

  virtual int add(int from, int to, T cost) = 0;
};

template <typename T>
class digraph : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  digraph(int _n) : graph<T>(_n) {
  }

  int add (int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    edges.push_back({from , to, cost});
    return id;
  }

  digraph<T> reverse() const {
    digraph<T> rev(n);
    for (auto& e: edges) {
      rev.add(e.to, e.from, e.cost);
    }
    return rev;
  }
};

template <typename T>
std::vector<int> find_scc(const digraph<T> &g, int &cnt) {
  digraph<T> g_rev = g.reverse();
  std::vector<int> order;
  std::vector<bool> was(g.n, false);
  std::function<void(int)> dfs1 = [&](int v) {
    was[v] = true;
    for (int id : g.g[v]) {
      auto &e = g.edges[id];
      int to = e.to;
      if (!was[to]) {
        dfs1(to);
      }
    }
    order.push_back(v);
  };
  for (int i = 0; i < g.n; i++) {
    if (!was[i]) {
      dfs1(i);
    }
  }
  std::vector<int> c(g.n, -1);
  std::function<void(int)> dfs2 = [&](int v) {
    for (int id : g_rev.g[v]) {
      auto &e = g_rev.edges[id];
      int to = e.to;
      if (c[to] == -1) {
        c[to] = c[v];
        dfs2(to);
      }
    }
  };
  cnt = 0;
  for (int id = g.n - 1; id >= 0; id--) {
    int i = order[id];
    if (c[i] != -1) {
      continue;
    }
    c[i] = cnt++;
    dfs2(i);
  }
  return c;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  digraph<int> g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g.add(a, b);
  }
  int cnt = 0;
  vector<int> s = find_scc(g, cnt);
  if (cnt == 1) {
    cout << "YES" << '\n';
    return 0;
  }
  int beg = -1;
  int end = -1;
  for (int i = 1; i < n; i++) {
    if (s[i] != s[0]) {
      beg = 0;
      end = i;
      break;
    }
  }
  constexpr int inf = (int) 1e9;
  vector<int> dist(n, inf);
  queue<int> q;
  dist[beg] = 0;
  q.push(beg);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int id : g.g[u]) {
      auto &e = g.edges[id];
      int v = e.from ^ e.to ^ u;
      if (dist[v] == inf) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  if (dist[end] < inf) {
    swap(beg, end);
  }
  cout << "NO" << '\n';
  cout << beg + 1 << " " << end + 1 << '\n';
  return 0;
}
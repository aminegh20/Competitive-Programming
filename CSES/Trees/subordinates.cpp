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
class forest : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;
 
  forest(int _n) : graph<T>(_n) {
  }
 
  int add (int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    assert(id < n - 1);
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};
 
template <typename T>
class dfs_forest : public forest<T> {
  public:
  using forest<T>::edges;
  using forest<T>::g;
  using forest<T>::n;
 
  std::vector<int> pv;
  std::vector<int> pe;
  std::vector<int> order;
  std::vector<int> pos;
  std::vector<int> end;
  std::vector<int> sz;
  std::vector<int> root;
  std::vector<int> depth;
  std::vector<T> dist;
  
  dfs_forest(int _n) : forest<T>(_n) {
  }
 
  void init () {
    pv = std::vector<int>(n, - 1);
    pe = std::vector<int>(n, -1);  
    order.clear();
    pos = std::vector<int>(n, -1);
    end = std::vector<int>(n, -1);
    sz = std::vector<int>(n, 0);
    root = std::vector<int>(n, -1);
    depth = std::vector<int>(n, -1);
    dist = std::vector<T>(n);
  }
 
  void clear () {
    pv.clear();
    pe.clear();
    order.clear();
    pos.clear();
    end.clear();
    sz.clear();
    root.clear();
    depth.clear();
    dist.clear();
  }
 
  private:
  void do_dfs (int v) {
    pos[v] = (int) order.size();
    order.push_back(v);
    sz[v] = 1;
    for (int id : g[v]) {
      if (id == pe[v]) {
        continue;
      }
      auto &e = edges[id];
      int to = e.from ^ e.to ^ v;
      depth[to] = depth[v] + 1;
      dist[to] = dist[v] + e.cost;
      pv[to] = v;
      pe[to] = id;
      root[to] = (root[v] != -1 ? root[v] : to);
      do_dfs(to);
      sz[v] += sz[to];
    }
    end[v] = order.size() - 1;
  }
 
  void do_dfs_from (int v) {
    depth[v] = 0;
    dist[v] = T{};
    root[v] = v;
    pv[v] = pe[v] = - 1;
    do_dfs(v);
  }
 
  public:
  void dfs (int v, bool clear_order = true) {
    if (pv.empty()) {
      init();
    } else if (clear_order) {
      order.clear();
    }
    do_dfs_from(v);
  }
};
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  dfs_forest<int> g(n);
  for (int i = 1; i < n; ++i) {
    int boss;
    cin >> boss;
    boss--;
    g.add(boss, i);
 
  }
  g.dfs(0);
  for (int i = 0; i < n; ++i) {
    cout << g.sz[i] - 1 << " ";
  }
  cout << '\n';
  return 0;
}
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
class undigraph : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  undigraph(int _n) : graph<T>(_n) {
  }

  int add (int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

class dsu {
  public:
  std::vector<int> p;
  int n;
  
  dsu(int _n) : n(_n) {
    p.resize(n);
    std::iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

template <typename T>
std::vector<int> find_mst (const undigraph<T> &g, T &ans) {
  std::vector<int> order(g.edges.size());
  std::iota(order.begin(), order.end(), 0);
  std::sort(order.begin(), order.end(), [&g] (int a, int b) {
    return g.edges[a].cost < g.edges[b].cost;
  });
  dsu d(g.n);
  std::vector<int> ans_list;
  ans = T{};
  for (int id : order) {
    auto &e = g.edges[id];
    if (d.get(e.from) != d.get(e.to)) {
      d.unite(e.from, e.to);
      ans_list.push_back(id);
      ans += e.cost;
    }
  }
  return ans_list;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  dsu d(n);
  undigraph<long long> g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    long long c;
    cin >> c;
    g.add(a, b, c);
    d.unite(a, b);
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += d.get(i) == i;
  }
  if (cnt > 1) {
    cout << "IMPOSSIBLE" << '\n';
    return 0;
  }
  long long ans = 0;
  find_mst(g, ans);
  cout << ans << '\n';
  return 0;
}
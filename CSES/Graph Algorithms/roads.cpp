#include <bits/stdc++.h>
using namespace std;

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

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  dsu d(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    d.unite(a, b);
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += d.get(i) == i;
  }
  cout << cnt - 1 << '\n';
  for (int i = 1; i < n; i++) {
    if (d.get(i) == i && d.get(i) != d.get(0)) {
      cout << d.get(0) + 1 << " " << i + 1 << '\n';
    }
  }
  return 0;
}
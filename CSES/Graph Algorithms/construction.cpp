#include <bits/stdc++.h>
using namespace std;

class dsu {
  public:
  std::vector<int> p;
  std::vector<int> size;
  int max;
  int number;
  int n;
  
  dsu(int _n) : n(_n) {
    max = 1;
    number = n;
    size.resize(n, 1);
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
      size[y] += size[x];
      number -= 1;
      max = std::max(max, size[y]);
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
    cout << d.number << " " << d.max << '\n';
  }
  return 0;
}
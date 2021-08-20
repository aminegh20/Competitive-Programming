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
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dsu d(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.') {
        if (i + 1 < n && a[i + 1][j] == '.') {
          d.unite(i * m + j, (i + 1) * m + j);
        }
        if (j + 1 < m && a[i][j + 1] == '.') {
          d.unite(i * m + j, i * m + j + 1);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.') {
        ans += d.get(i * m + j) == i * m + j;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
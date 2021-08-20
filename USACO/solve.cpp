#include <bits/stdc++.h>
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef LOCAL
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
#endif  
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<string> b(n * k, string(m * k, ' '));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 'X') {
        for (int ii = i; ii < ii + k; ++ii) {
          b[i]
        }
      }
    }
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
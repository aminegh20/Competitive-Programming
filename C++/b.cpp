#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    reverse(a.begin(), a.end());
    int ans = 0;
    set<int> s;
    for (int i = 0; i < n; i++) {
      if (!s.empty() && *s.begin() < a[i]) {
        ans += 1;
      }
      s.emplace(a[i]);
    }
    cout << ans << '\n';
  } 
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<array<int, 2>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
  } 
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return a[i][0] < a[j][0]; 
  });
  vector<int> ans(n);
  int cnt = ans[order[0]] = 1;
  set<pair<int, int>> s;
  s.emplace(a[order[0]][1], order[0]);
  for (int j = 1; j < n; j++) {
    int i = order[j];
    auto room = *s.begin();
    if (room.first < a[i][0]) {
      ans[i] = ans[room.second];
      s.erase(room);
    } else {
      ans[i] = ++cnt;
    }
    s.emplace(a[i][1], i);
  }
  cout << cnt << '\n';
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
  return 0;
}
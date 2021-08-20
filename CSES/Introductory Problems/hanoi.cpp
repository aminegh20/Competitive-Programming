#include <bits/stdc++.h>
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> moves;
  function<void(int, int, int, int)> Hanoi = [&](int n, int a, int b, int c) -> void {
    if (n == 1) {
      moves.emplace_back(a, c);
    }
    Hanoi(n - 1, a, c, b);
    moves.emplace_back(c, a);
    Hanoi(n - 1, b, c, a);
  };
  Hanoi(n, 1, 2, 3);
  cout << moves.size() << '\n';
  for (auto [x, y] : moves) {
    cout << x << " " << y << '\n';
  }
  return 0;
}
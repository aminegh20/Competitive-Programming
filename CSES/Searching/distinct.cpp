#include <bits/stdc++.h>
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int n; 
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; ++i) { 
    int x; 
    cin >> x;
    s.emplace(x);
  }
  cout << s.size() << '\n';
  return 0;
}
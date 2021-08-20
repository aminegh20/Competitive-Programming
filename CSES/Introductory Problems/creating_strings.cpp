#include <bits/stdc++.h>
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  vector<int> fact(n + 1);
  fact[0] = 1;
  for (int i = 1; i < n + 1; i++) {
    fact[i] = fact[i - 1] * i;
  } 
  vector<int> f(26);
  for (char c : s) {
    f[c - 'a'] += 1;
  }
  int ans = fact[n];
  for (int ch = 0; ch < 26; ch++) {
    ans /= fact[f[ch]];
  }
  cout << ans << '\n';
  sort(s.begin(), s.end());
  do {
    cout << s << '\n';
  } while (next_permutation(s.begin(), s.end()));
  return 0;
}
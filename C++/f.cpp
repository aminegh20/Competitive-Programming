
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n, k;
    cin >> n >> k;
    string ans;
    for (int d = 1; d < 10; d++) {
      char c = (char) d + '0';
      string number;
      number += c;
      while (stoll(number) < n) {
        number += c;
      }
      if (ans == "" || (stoll(number) < stoll(ans) && stoll(number) >= n)) {
        ans = number;
      }
    }
    if (k == 1) {
      cout << ans << '\n';
      continue;
    }

    string s = to_string(n);
    int m = (int) s.size();
    string ok;
    char main = s[0];
    for (int d = 0; d < 10; d++) {
      if (d == main) continue;
      for (int mask = 0; mask < (1 << (m - 1)); mask++) {
        string youssef;
        for (int i = 0; i < m - 1; i++) {
          if (mask & (1 << i)) {
            youssef += main;
          } else {
            youssef += (char) d + '0';
          }
        }
        string amine = main + youssef;
        if (stoll(amine) < n) {
          continue;
        }
        if (ok == "" || (stoll(amine) < stoll(ok) && stoll(amine) >= n)) {
          ok = amine;
        }
      }
    }
    if (ok.size()) {
      cout << min(stoll(ok), stoll(ans)) << '\n';
    } else {
      cout << ans << '\n';
    }
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

constexpr int Fun() { return 1; }

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<int> id(26, (int) 1e9);
    vector<int> f(26);
    for (int i = 0; i < n; i++) {
      id[s[i] - 'a'] = i;
      f[s[i] - 'a']++;
    }
    int d = set<char>(s.begin(), s.end()).size();
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return id[i] < id[j]; 
    });
    int STRING_SIZE = 0;
    bool ok = true;
    for (int i = 0; i < d; i++) {
      if (f[order[i]] % (i + 1)) {
        ok = false;
        break;
      } 
      STRING_SIZE += f[order[i]] / (i + 1);
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    string cnd = s.substr(0, STRING_SIZE);
    string may = cnd;
    for (int i = 0; i < d; i++) {
      string foo;
      for (char c : cnd) {
        if (c != (char) order[i] + 'a') {
          foo += c;
        }
        may += foo;
      }
    }
    if (may != s) {
      cout << -1 << '\n';
      continue;
    }
    cout << may << " ";
    for (int i = 0; i < d; i++) {
      cout << (char) order[i] + 'a';
    }
    cout << '\n';
  } 
  return 0;
}
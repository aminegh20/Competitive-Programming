#include <bits/stdc++.h>
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq < tt + 1; ++qq) {
    cout << "Case #" << qq << ": ";
    long long n, k, v;
    cin >> n >> k >> v;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    string ptr = a[(v - 1) % (n - k + 1) + k - 1];
    for (int i = 0; i < k - 1; ++i) {
      cout << a[i] << " ";
    }
    cout << ptr << '\n';
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    long long n, m;
    cin >> n >> m;
    long long dig = m % 10LL;
    long long k = m + m;
    vector<long long> digits;
    digits.emplace_back(dig);
    while (k % 10LL != digits[0]) {
      digits.emplace_back(k % 10LL);
      k += m;
    }
    long long q = n / m;
    long long s = (int) digits.size();
    long long tot = accumulate(digits.begin(), digits.end(), 0LL);
    long long ans = tot * (q / s);
    for (int i = 0; i < q % s; i++) {
      ans += digits[i];
    }
    cout << ans << '\n';
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  long long tot = 0;
  for (int i = 0; i < n - 1; i++) {
    long long x;
    cin >> x;
    tot += x;
  } 
  cout << n * (n + 1) / 2 - tot << '\n';
  return 0;
}
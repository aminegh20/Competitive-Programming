#include <bits/stdc++.h>
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  while (n > 1) {
    cout << n << " ";
    n = (n & 1 ? 3 * n + 1 : (n >> 1));
  } 
  cout << n << '\n';
  return 0;
}
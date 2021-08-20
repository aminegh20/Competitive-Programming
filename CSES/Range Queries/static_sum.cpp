#include <bits/stdc++.h>
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, qq;
  cin >> n >> qq;
  vector<long long> pr(n + 1);
  for (int i = 1; i < n + 1; i++) {
    cin >> pr[i];
    pr[i] += pr[i - 1];
  } 
  while (qq--) {
    int L, R;
    cin >> L >> R;
    cout << pr[R] - pr[L - 1] << '\n';
  }
  return 0;
}
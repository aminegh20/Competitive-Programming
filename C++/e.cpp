#include <bits/stdc++.h>
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  auto JIHAD = [&](string cnd) -> bool {
    for (int i = 0; i < 3 * n; i++) {
      string sub = cnd.substr(i, 2);
      if (sub == s || sub == t) {
        return false;
      }
    }
    return true;
  };
  bool ok = false;
  string ABC = "abc";
  do {
    string KARIM;
    for (int i = 0; i < n; i++) {
      KARIM += ABC;
    }
    string CHARBEL;
    CHARBEL += string(n, ABC[0]);
    CHARBEL += string(n, ABC[1]);
    CHARBEL += string(n, ABC[2]);
    if (JIHAD(KARIM)) {
      cout << "YES" << '\n';
      cout << KARIM << '\n';
      ok = true;
      break;
    }
    if (JIHAD(CHARBEL)) {
      cout << "YES" << '\n';
      cout << CHARBEL << '\n';
      ok = true;
      break;
    }
  } while (next_permutation(ABC.begin(), ABC.end()));
  if (!ok) {
    cout << "NO" << '\n';
  }
  return 0;
}
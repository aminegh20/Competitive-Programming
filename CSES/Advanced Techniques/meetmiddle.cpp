#include <bits/stdc++.h>
using namespace std;
 
#include<bits/extc++.h>
struct splitmix64_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
 
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
 
template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;
 
template <typename K, typename Hash = splitmix64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<long long> a;
  vector<long long> b;
  for (int i = 0; i < n; ++i) {
    long long t;
    cin >> t;
    (i & 1 ? a : b).push_back(t);
  } 
  auto Get = [](vector<long long> a) -> vector<long long> {
    int n = (int) a.size();
    vector<long long> ans_list;
    for (int mask = 0; mask < (1 << n); ++mask) {
      long long sum = 0;
      for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
          sum += a[i];
        }
      }
      ans_list.push_back(sum);
    }
    return ans_list;
  };
  vector<long long> subA = Get(a);
  vector<long long> subB = Get(b);
  hash_map<long long, long long> mp;
  for (long long value : subB) {
    mp[value]++;
  }
  long long ans = 0;
  for (long long value : subA) {
    if (x - value < 0 || mp.find(x - value) == mp.end()) {
      continue;
    } 
    ans += mp[x - value];
  }
  cout << ans << '\n';
  return 0;
}
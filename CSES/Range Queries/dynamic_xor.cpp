#include <bits/stdc++.h>
using namespace std;
 
template <typename T>
class segtree {
  public:
  struct node {
    T sum = T{};
    T max = T{};
    T min = static_cast<T>(std::is_same<int, T>::value ? 1e9 : 1e18);
    T xor_value = T{};
 
    inline void apply(T v) {
      sum = v;
      max = v;
      min = v;
      xor_value = v;
    }
  };
 
  int n;
  std::vector<node> tree;
 
  private:
  node unite(const node &a, const node &b) {
    node res;
    res.sum = a.sum + b.sum;
    res.min = std::min(a.min, b.min);
    res.max = std::max(a.max, b.max);
    res.xor_value = a.xor_value ^ b.xor_value;
    return res;
  }
 
  inline void pull(int x) {
    tree[x] = unite(tree[2 * x + 1], tree[2 * x + 2]);
  }
 
  void build(int x, int L, int R, const std::vector<T> &a) {
    if (R == L + 1) {
      if (L < (int) a.size()) {
        tree[x].apply(a[L]);
      }
      return;
    }
    int y = (L + R) >> 1;
    build(2 * x + 1, L, y, a);
    build(2 * x + 2, y, R, a);
    pull(x);
  }
 
  void modify(int i, T v, int x, int L, int R) {
    if (R == L + 1) {
      tree[x].apply(v);
      return;
    }
    int y = (L + R) >> 1;
    if (i >= y) {
      modify(i, v, 2 * x + 2, y, R);
    } else {
      modify(i, v, 2 * x + 1, L, y);
    }
    pull(x);
  }
 
  node get(int x, int L, int R, int Lx, int Rx) {
    if (Lx >= R || Rx <= L) {
      return node{};
    }
    if (Lx >= L && Rx <= R) {
      return tree[x];
    }
    int y = (Lx + Rx) >> 1;
    node a = get(2 * x + 1, L, R, Lx, y);
    node b = get(2 * x + 2, L, R, y, Rx);
    node res = unite(a, b);
    return res;
  }
 
  int find_kth_one(int x, int k, int L, int R) {
    if (R == L + 1) {
      return L;
    }
    int y = (L + R) >> 1;
    int s = tree[2 * x + 1].sum;
    return (s > k ? find_kth_one(2 * x + 1, k, L, y) : find_kth_one(2 * x + 2, k - s, y, R));
  }
 
  T find_first(T v, int x, int L, int R) {
    if (R == L + 1) {
      return L;
    }
    int y = (L + R) >> 1;
    int mx = tree[2 * x + 1].max;
    return (mx + 1 > v ? find_first(v, 2 * x + 1, L, y) : find_first(v, 2 * x + 2, y, R));
  }
 
  T find_first_from(T v, int x, int L, int R, int from) {
    if (tree[x].max < v || R <= from) {
      return -1;
    }
    if (R == L + 1) {
      return L;
    }
    int y = (L + R) >> 1;
    if (y < from) {
      return find_first_from(v, 2 * x + 2, y, R, from);
    }
    int ret = find_first_from(v, 2 * x + 1, L, y, from); 
    return (ret == -1 ? find_first_from(v, 2 * x + 2, y, R, from) : ret);
  }
 
  public:
  segtree (const std::vector<T> &a) {
    n = (int) a.size();
    n = 1 << (32 - __builtin_clz(n));
    tree.assign(2 * n, node{});
    build(0, 0, n, a);
  }
 
  segtree(int n_) {
    n = n_;
    n = 1 << (32 - __builtin_clz(n));
    tree.assign(2 * n, node{});
  }
 
  inline void modify(int i, T v) {
    modify(i, v, 0, 0, n);
  }
 
  inline node get(int L, int R) {
    return get(0, L, R + 1, 0, n);
  }
 
  inline int find_kth_one(int k) {
    return find_kth_one(0, k, 0, n);
  }
 
  inline T find_first(T v) {
    return tree[0].max < v ? -1 : find_first(v, 0, 0, n);
  }
 
  inline T find_first_from(T v, int L) {
    return get(L, n - 1).max < v ? -1 : find_first_from(v, 0, 0, n, L);
  }
};
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  segtree<long long> st(a);
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << st.get(a - 1, b - 1).xor_value << '\n';
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF LLONG_MAX
#define pb push_back
#define all(v) v.begin(), v.end()

const int mod = 1e9+7;

vector<int> seg, a;

int seg_query(int p, int i, int j, int l, int r) {
  if(j < l || i > r) return INF;
  if(i >= l && j <= r) return seg[p];
  int m = (i+j) >> 1;
  return min(seg_query(p*2, i, m, l, r), seg_query(p*2+1, m+1, j, l, r));
}
int seg_update(int p, int i, int j, int target, int v) {
  if(target < i || target > j) return seg[p];
  if(i == j) return seg[p] = v;
  int m = (i+j) >> 1;
  return seg[p] = min(seg_update(p*2, i, m, target, v), seg_update(p*2+1, m+1, j, target, v));
}

int seg_build(int p, int i, int j) {
  if(i == j) return seg[p] = a[i];
  int m = (i+j) >> 1;
  return seg[p] = min(seg_build(p*2, i, m), seg_build(p*2+1, m+1, j));
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0); 
  int n, m;
  cin >> n >> m;
  seg = vector<int>(n*4);
  a = vector<int>(n);
  for(int &i : a) cin >> i;
  seg_build(1, 0, n-1);
  while(m--) {
    int t, x, y;
    cin >> t >> x >> y;
    if(t == 1) seg_update(1, 0, n-1, x, y);
    else cout << seg_query(1, 0, n-1, x, y-1) << '\n';
  }
  return 0;
}
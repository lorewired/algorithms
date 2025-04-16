#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

vector<int> seg, v;

int seg_query(int p, int i, int j, int l, int r) {
  if(i > r || j < l) return 0;
  if(i == j) return seg[p];
  int m = (i+j) >> 1;
  return seg_query(p*2, i, m, l, r) + seg_query(p*2+1, m+1, j, l, r);
}

int seg_update(int p, int i, int j, int x, int y) {
  if(x < i || x > j) return seg[p];
  if(i == j) return seg[p] = y;
  int m = (i+j) >> 1;
  return seg[p] = seg_update(p*2, i, m, x, y) + seg_update(p*2+1, m+1, j, x, y);
}

int seg_build(int p, int i, int j) {
  if(i == j) return seg[p] = v[i];
  int m = (i+j) >> 1;
  return seg[p] = seg_build(p*2, i, m) + seg_build(p*2+1, m+1, j);
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  v = vector<int>(n);
  seg = vector<int>(n*4);
  for(int &i : v) cin >> i;
  seg_build(1, 0, n-1);
  while(m--) {
    int t, x, y;
    cin >> t >> x >> y;
    if(t == 1) seg_update(1, 0, n-1, x, y);
    else cout << seg_query(1, 0, n-1, x, y-1) << '\n';
  }
  return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define inf INT_MAX
const int mod = 1e9+7;
using namespace std;

vector<vector<int>> dp;

int f(int i, int v) {
  if(i > 6) return !v ? 1 : 0;
  int use = v-i >= 0 ? f(i, v-i) : 0;
  int skip = f(i+1, v);
  return use + skip;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n;
  cin >> n;
  dp.assign(7, vector<int>(1000001, -1));
  cout << f(1, n);
  return 0;
}
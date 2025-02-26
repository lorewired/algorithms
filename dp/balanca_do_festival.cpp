#include <bits/stdc++.h>
#define ll long long
#define inf INT_MAX
const int mod = (int)1e9+7;
using namespace std;

int n, k, dp[10001][10001], cost[10001];

int f(int i, int v) {
  if(v == 0) return 0;
  if(i == n || v < 0) return inf;
  if(dp[i][v] != -1) return dp[i][v];
  int use = v-cost[i] >= 0 ? f(i, v-cost[i]) : inf;
  int skip = f(i+1, v);
  return dp[i][v] = min(use, skip);
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> n >> k;
  for(int i=0;i<n;i++) cin >> cost[i];
  memset(dp, -1, sizeof(dp));
  int ans = f(0, k);
  cout << (!ans ? "SIM" : "NAO") << '\n';
  return 0;
}
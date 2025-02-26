#include <bits/stdc++.h>
#define ll long long
#define inf INT_MAX
const int mod = (int)1e9+7;
using namespace std;

ll n, dp[1000005];

int f(int v) {
  if(v == n) return 1;
  if (dp[v] != -1) return dp[v];
  int t = 0;
  for(int i = 1; i <= 6; i++) {
    if(v+i <= n) {
      t += f(v+i);
      t %= mod;
    }
  }
  return dp[v] = t;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> n;
  memset(dp, -1, (n+5)*sizeof(ll));
  cout << f(0);
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf LLONG_MAX
#define pb push_back
#define all(v) v.begin(), v.end()
#define lb lower_bound
#define ub upper_bound
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int mod = 1e9+7;

int cost[105], value[105], dp[105][100005], n;

int knap(int i, int cap) {
  if (i == n) return 0;
  if(dp[i][cap] != -1) return dp[i][cap];
  int use = cap-cost[i] >= 0 ? value[i] + knap(i+1, cap-cost[i]) : -inf;
  int skip = knap(i+1, cap);
  return dp[i][cap] = max(use, skip);
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  memset(dp, -1, sizeof(dp));
  int cap;
  cin >> n >> cap;
  for(int i = 0; i < n; i++) {
    int w, v;
    cin >> w >> v;
    cost[i] = w;
    value[i] = v;
  }
  cout << knap(0, cap) << '\n';
  return 0;
}

/* \    /\
    )  ( ') - use dp bro
   (  /  )
    \(__)|
*/

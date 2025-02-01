#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF LLONG_MAX
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

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vi c(n), dp(m+1);
  for(int &i : c) cin >> i;
  dp[0] = 1;
  for(int j=0; j<n; j++) {
    for(int i=1; i<=m; i++) {
      if(i >= c[j]) {
        dp[i] += dp[i-c[j]] % mod;
      }
    }
  }
  cout << dp[m] % mod << '\n';
  return 0;
}
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
  int n;
  cin >> n;
  vi v(n), dp(n);
  for(int &i : v) cin >> i;
  dp[0] = 0;
  dp[1] = abs(v[0]-v[1]);
  for(int i=2; i<n; i++) {
    dp[i] = min(abs(v[i]-v[i-2])+dp[i-2], abs(v[i]-v[i-1])+dp[i-1]);
  }
  cout << dp[n-1] << '\n';
  return 0;
}
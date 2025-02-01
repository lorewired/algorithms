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
  string s;
  int n;
  cin >> n >> s;
  vvi dp(n+1, vi(3));
  for(int i=1; i<=n; i++) {
    if(s[i-1] == 'R') {
      dp[i][0] = max(dp[i-1][1], dp[i-1][2]);
      dp[i][1] = max(dp[i-1][0], dp[i-1][2])+1;
    }
    if(s[i-1] == 'P') {
      dp[i][1] = max(dp[i-1][0], dp[i-1][2]);
      dp[i][2] = max(dp[i-1][0], dp[i-1][1])+1;
    }
    if(s[i-1] == 'S') {
      dp[i][2] = max(dp[i-1][0], dp[i-1][1]);
      dp[i][0] = max(dp[i-1][1], dp[i-1][2])+1;
    }
  }
  cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << '\n';
  return 0;
}
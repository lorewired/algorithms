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

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n[5] = {1, 2, 3, 4, 5};
  cout << (lower_bound(n, n+5, 6)-n) << '\n';
  return 0;
}

/* \    /\
    )  ( ') - use dp bro
   (  /  )
    \(__)|
*/
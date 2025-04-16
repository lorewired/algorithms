#include <bits/stdc++.h>
using namespace std;
#define int long long
#define eb emplace_back
#define ep emplace
#define inf LLONG_MAX
#define V vector
const int mod = 1e9+7;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

signed main() {
  int s, x, y, g = 0, l = inf;
  cin >> s >> x >> y;
  for(int i = x; i <= y; i++) {
    int tmp = i, sum = 0;
    while(tmp != 0 && sum <= s) {
      sum += tmp % 10;
      tmp /= 10;
    }
    if(sum == s) {
      g = max(g, i);
      l = min(l, i);
    }
  }
  cout << l << '\n' << g;
  return 0;
}
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
  int v[4];
  cin >> v[0] >> v[1] >> v[2] >> v[3];
  cout << abs((v[0] + v[3]) - (v[1] + v[2]));
  return 0;
}
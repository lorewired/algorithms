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

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

int pow_bin(int base, int expo, int mod) {
  int ret = 1;
  while(expo != 0) {
    if(expo & 1) ret = (ret * base) % mod;  
    base = (base * base) % mod;
    expo /= 2;
  }
  return ret;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  return 0;
}
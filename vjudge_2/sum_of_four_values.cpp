#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF LLONG_MAX
#define F first
#define S second
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
  int n, t;
  cin >> n >> t;
  vpi v(n);
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    v[i] = {x, i+1};
  }
  if(n < 4) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  map<int, vpi> mp;
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      int dif = t - (v[i].F+v[j].F);
      if(mp.count(dif)) {
        for(auto p : mp[dif]) {
          if(p.F != v[i].S && p.F != v[j].S && p.S != v[i].S && p.S != v[j].S) {
            cout << v[i].S << ' ' << v[j].S << ' ' << p.F << ' ' << p.S << '\n';
            return 0;
          }
        }
      }
      mp[v[i].F+v[j].F].pb({v[i].S, v[j].S});
    }
  }
  cout << "IMPOSSIBLE\n";
  return 0;
}

/* \    /\
    )  ( ') - use dp bro
   (  /  )
    \(__)|
*/
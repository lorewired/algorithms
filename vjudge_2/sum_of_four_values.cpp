#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, t;
  cin >> n >> t;
  if (n < 4) {
    cout << "IMPOSSIBLE\n";
  }
  else {
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
      v[i].s = i+1;
      cin >> v[i].f;
    }
    map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        int diff = t - (v[i].f + v[j].f);
        if (mp.count(diff)) {
          for (auto p : mp[diff]) {
            if (p.f != v[i].s && p.f != v[j].s && p.s != v[i].s && p.s != v[j].s) {
              cout << v[i].s << ' ' << v[j].s << ' ' << p.f << ' ' << p.s << '\n';
              return 0;
            }
          }
        }
        mp[v[i].f + v[j].f].pb({v[i].s, v[j].s});
      }
    }
    cout << "IMPOSSIBLE\n";
  }
  return 0;
}   
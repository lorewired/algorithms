#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pi pair<int, int>
#define bg begin()
#define en end()
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, t;
  cin >> n >> t;
  if (n < 2) {
    cout << "IMPOSSIBLE\n";
  } else {
    vector<pi> v(n);
    for (int i = 0; i < n; i++) {
      v[i].s = i+1;
      cin >> v[i].f;
    }
    sort(all(v));
    for (int i = 0; i < n; i++) {
      int diff = t - v[i].f;
      int idx = lb(v.bg+i+1, v.en, make_pair(diff, -1)) - v.bg;
      if (idx < n && v[i].f + v[idx].f == t) {
        cout << v[i].s << ' ' << v[idx].s << '\n';
        return 0;
      }
    }
    cout << "IMPOSSIBLE\n";
  }
  return 0;
}
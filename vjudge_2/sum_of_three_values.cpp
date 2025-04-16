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
  if (n < 3) {
    cout << "IMPOSSIBLE\n";
  } else {
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
      v[i].s = i+1;
      cin >> v[i].f;
    }
    sort(all(v));
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        int diff = t - (v[i].f + v[j].f);
        int low = lb(v.begin()+j+1, v.end(), make_pair(diff,-1)) - v.begin();
        if (low < n && v[i].f + v[j].f + v[low].f == t) {
          cout << v[i].s << ' ' << v[j].s << ' ' << v[low].s << '\n';
          return 0;
        }
      }
    }
    cout << "IMPOSSIBLE\n";
  }
  return 0;
}
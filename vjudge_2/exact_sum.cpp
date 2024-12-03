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
    while (cin >> n) {
      vector<int> v(n);
      for (int &i : v) cin >> i;
      cin >> t;
      sort(all(v));
      vector<pi> ans;
      for (int i = 0; i < n; i++) {
        int idx = lb(v.bg+i+1, v.en, t - v[i]) - v.bg;
        if (idx < n && v[idx] == t - v[i])
          ans.pb({v[i], v[idx]});
      }
      sort(all(ans), [] (pi p1, pi p2) {
        return abs(p1.f - p1.s) < abs(p2.f - p2.s);
      });
      cout << "Peter should buy books whose prices are " << ans[0].f << " and " << ans[0].s << ".\n\n";
    }
    return 0;
  }
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
  int c, s, t;
  cin >> c;
  while (c--) {
    cin >> s >> t;
    vector<int> v(s), pref(s);
    for (int &i : v) cin >> i;
    pref[0] = v[0];
    for (int i = 1; i < s; i++)
      pref[i] = v[i] + pref[i - 1];
    int l = sz(v)/2-1, r = sz(v)/2;
    if (pref[s-1] < t) {
      cout << -1;
    } else {
      cout << pref[s-2]-pref[]
      //while (l >= 0 || r < s) {
      //  
      //}
    }

    cout << '\n';
  }
  return 0;
}
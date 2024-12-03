#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  while (cin >> n) {
    vector<int> a(n);
    for (int &i : a)
      cin >> i;
    cin >> q;
    for (int i = 0; i < q; i++) {
      int x, less = 0;
      cin >> x;
      auto r = upper_bound(a.begin(), a.end(), x) - a.begin();
      auto l = lower_bound(all(a), x) - a.begin();
      if (l > 0) less = a[l- 1];
      if (!less) cout << 'X';
      else cout << less;
      if (r >= n) cout << " X";
      else cout << ' ' << a[r];
      if (i+1 < n) cout << '\n';
      //cout << (!less ? "X" : to_string(less)) << ' ' << (r>=n ? "X" : to_string(a[r])) << (i+1 == n ? "" : "\n");
    }
  }
  return 0;
}
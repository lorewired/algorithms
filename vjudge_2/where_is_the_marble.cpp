#include <bits/stdc++.h>
using namespace std;

signed main() {
  int n, q, c = 1;
  while (cin >> n >> q && n && q) {
    vector<int> v(n), qu(q);
    for (int &i : v)
      cin >> i;
    for (int &i : qu)
      cin >> i;
    sort(v.begin(), v.end());
    cout << "CASE# " << c++ << ":\n";
    for (int i = 0; i < q; i++) {
      int low = lower_bound(v.begin(), v.end(), qu[i]) - v.begin();
      if (low < n && v[low] == qu[i])
        cout << qu[i] << " found at " << low + 1;
      else
        cout << qu[i] << " not found";
      cout << '\n';
    }
  }
  return 0;
}
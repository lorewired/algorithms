#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define pi pair<int, int>
#define bg begin()
#define en end()
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }
  while (k--) {
    int x;
    cin >> x;
    int l = -1, r = n;
    bool ok = false;
    while (r > l+1) {
      int mid = (l+r) / 2;
      if (a[mid] < x) {
        l = mid;
      }
      else {
        r = mid;
      }
    }
    cout << (r == -1 ? 0 : r+1) << '\n';
  }
  return 0;
}
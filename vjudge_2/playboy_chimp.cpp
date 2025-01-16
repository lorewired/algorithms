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
    }
  }
  return 0;
}

/*
APENAS COM UPPER_BOUND

#include <bits/stdc++.h>
#define import <ElPsyKongroo>
#define io ios_base::sync_with_stdio(false);
#define ll long long
using namespace std;

signed main() {
    io;
    int n, q;
    cin >> n;
    int arr[n];
    for (int &i : arr)
        cin >> i;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        int idx = upper_bound(arr, arr+n, x) - arr;
        int ant, post;
        if (arr[idx-1] != x) {
            if (idx-1 < 0) ant = -1;
            else ant = arr[idx-1];
        } else {
            int cur = idx-1;
            while (arr[cur] == x) {
                cur--;
            }
            if (cur < 0) ant = -1;
            else ant = arr[cur];
        }
        post = idx >= n ? -1 : arr[idx];
        cout << (ant == -1 ? "X" : to_string(ant)) << ' ';
        cout << (post == -1 ? "X" : to_string(post)) << '\n';
    }
    return 0;
}
*/
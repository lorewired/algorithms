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
  int n;
  cin >> n;
  vector<string> v(n);
  for (string &str : v) cin >> str;
  sort(all(v), [] (const string a, const string b) {
    int sa = sz(a), sb = sz(b);
    return sa == sb ? a < b : sa 
  });
  for (string str : v) cout << str;
  cout << '\n';
  return 0;
}
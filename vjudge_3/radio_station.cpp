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
  int n, m;
  cin >> n >> m; cin.ignore();
  map<string, string> sv;
  string l, a, b;
  while (n--) {
    getline(cin, l);
    stringstream ss(l);
    ss >> a >> b;
    sv[b] = a;
  }
  while (m--) {
    getline(cin, l);
    stringstream ss(l);
    ss >> a >> b;
    b.pop_back();
    cout << a << ' ' << b << "; #" << sv[b] << '\n';
  }
  return 0;
}
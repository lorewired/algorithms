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
  ifstream in("bcount.in");
  ofstream out("bcount.out");
  int n, m, x;
  in >> n >> m;
  vector<int> v1, v2, v3;
  for (int i = 0; i < n; i++) {
    cin >> x;
    switch (x) {
    case 1: v1.pb(i); break;
    case 2: v2.pb(i); break;
    case 3: v3.pb(i); break;
    }
  }
  vector<>
  return 0;
}
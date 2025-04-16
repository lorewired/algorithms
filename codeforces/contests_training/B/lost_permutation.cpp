#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

void solve() {
  int n, m;
  cin>>n>>m;
  int s=m, g=0;
  rep(i,n) {
    int x;
    cin>>x;
    s+=x;
    g=max(x,g);
  }
  int c=0, i;
  for(i=1; c<s; i++) c+=i;
  cout<<(c!=s||i<=g?"NO":"YES")<<'\n';
} 

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt; cin >> tt;
  while (tt--)
    solve();
  return 0;
}
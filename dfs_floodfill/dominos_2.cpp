#include <bits/stdc++.h>
#define int long long
#define IOS \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr)
using namespace std;

vector<vector<int>> nodes;
vector<bool> vis;
int c = 0;

void fall(int i) {
  if (!vis[i]) c++;
  else  vis[i] = true;
  for (int n : nodes[i])
    if (!vis[n])
      fall(n);
}

int32_t main(){
  IOS;
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, l;
    cin >> n >> m >> l;
    nodes = vector<vector<int>>(n+1);
    vis = vector<bool>(n+1, 0);
    while (m--) {
      int x, y;
      cin >> x >> y;
      nodes[x].push_back(y);
    }
    while (l--) {
      int z;
      cin >> z;
      fall(z);
    }
    cout << c << '\n';
    c = 0;
  }
  return 0;
}
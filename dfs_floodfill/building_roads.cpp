#include <bits/stdc++.h>

#define import <ElPsyKongroo>
#define int long long
#define IOS \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr)

using namespace std;

vector<set<int>> nodes;
vector<bool> vis;
vector<int> bridges;

void dfs(int v) {
  vis[v] = 1;
  for (int sub : nodes[v]) {
    if (!vis[sub]) {
      dfs(sub);
    }
  }
}

int32_t main()
{
  IOS;
  int n, m;
  cin >> n >> m;
  nodes.resize(n+1); vis.resize(n+1, 0);
  while (m--) {
    int x, y;
    cin >> x >> y;
    nodes[x].insert(y);
    nodes[y].insert(x);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      bridges.push_back(i);
      dfs(i);
    }
  }
  int sz = bridges.size();
  cout << sz-1 << '\n';
  for (int i = 0; i < sz-1; i++) {
    cout << bridges[i] << ' ' << bridges[i+1] << '\n';
  }
  return 0;
}
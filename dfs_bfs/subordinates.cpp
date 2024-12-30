#include <bits/stdc++.h>

#define import <ElPsyKongroo>
#define int long long
#define IOS \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr)

using namespace std;

vector<vector<int>> nodes;
vector<int> ans;

int dfs(int v) {
  int c = 0;
  for (int sub : nodes[v]) {
    c++;
    c += dfs(sub);
  }
  ans[v] = c;
}

signed main()
{
  IOS;
  int n;
  cin >> n;
  nodes.resize(n+1); ans.resize(n+1);
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    nodes[x].push_back(i);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define V vector
#define _ cin.tie(0)->sync_with_stdio(0);

typedef long long ll;

int main() { _
  int n, m;
  cin >> n >> m;
  V<V<int>> adj(n+1);
  V<int> used(n+1);
  while(m--) {
    int x, y;
    cin >> x >> y;
    adj[x].emplace_back(y);
    adj[y].emplace_back(x);
  }
  function<void(int)> dfs=[&](int v){
    used[v]=1;
    for(int u:adj[v])
      if(!used[u])
        dfs(u);
  };
  V<int> ans;
  for(int i=1;i<=n;i++) {
    if(!used[i]) {
      ans.emplace_back(i);
      dfs(i);
    }
  }
  cout<<ans.size()-1<<'\n';
  for(int i=0;i<ans.size()-1;i++)
    cout<<ans[i]<<' '<<ans[i+1]<<'\n';
  exit(0);
}
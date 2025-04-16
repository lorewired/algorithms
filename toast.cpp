#include <bits/stdc++.h>
using namespace std;

#define V vector
#define ar array
#define _ cin.tie(0)->sync_with_stdio(0);

typedef long long ll;

const int M=(int)1e9+7, mxN=500;

int main() { _
  int n, m, q;
  cin >> n >> m >> q;
  V<V<ll>> adj(mxN, V<ll>(mxN, M));
  for(int i=0; i<=n; i++) adj[i][i]=0;
  for(int i=0; i<m; i++) {
    int a, b, c;
    cin >> a >> b >> c, a--, b--;
    adj[a][b]=adj[b][a]=min(adj[a][b], 1LL*c);
  }
  for(int k=0; k<=n; k++)
    for(int i=0; i<=n; i++)
      for(int j=0; j<=n; j++)
        if(adj[i][k]!=M&&adj[k][j]!=M)
          adj[i][j]=min(adj[i][k]+adj[k][j], adj[i][j]);
  while(q--) {
    int a, b;
    cin >> a >> b, a--, b--;
    cout << (adj[a][b]==M?-1:adj[a][b]) << "\n";
  }
  exit(0);
}
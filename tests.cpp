#include <bits/stdc++.h>
<<<<<<< HEAD
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
  vis[i] = true;
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
=======
#define f first
#define s second
#define pb push_back
#define pi pair<int, int>
#define bg begin()
#define en end()
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,x;
  cin>>n>>m;
  vector<int> v1(n,0),v2(n,0),v3(n,0);
  for(int i=0; i<n; i++){
    cin>>x;
    switch(x){
    case 1: v1[i]=x; break;
    case 2: v2[i]=x; break;
    case 3: v3[i]=x; break;
    }
  }
  auto ps=[](vector<int>& v) -> vector<int>{
    int s=sz(v);
    vector<int> tmp(s);
    tmp[0]=v[0];
    for(int i=1; i<s; i++) tmp[i]=v[i]+tmp[i-1];
    return tmp;
  };
  vector<int> pref1=ps(v1),pref2=ps(v2),pref3=ps(v3);
  for(int i : v1) cout<<i<<' ';
  cout<<'\n';
  for(int i : v2) cout<<i<<' ';
  cout<<'\n';
  for(int i : v3) cout<<i<<' ';
  cout<<'\n';
  return 0;
  while(m--){
    int l,r;
    cin>>l>>r;
    l--; r--;
    cout<<(!l ? pref1[r] : pref1[r]-pref1[l-1])<<' ';
    cout<<(!l ? pref2[r] : pref2[r]-pref2[l-1])<<' ';
    cout<<(!l ? pref3[r] : pref3[r]-pref3[l-1])<<'\n';
  }
  return 0;
}
>>>>>>> d780903d74a5fa88b09ff15e2fd3d9c9d76df2d9

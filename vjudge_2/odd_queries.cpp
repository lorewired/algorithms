#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define bg begin()
#define en end()
#define sz(x) (int)x.size()
#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int>>

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int c;
  cin>>c; 
  while(c--){
    int s, q;
    cin>>s>>q;
    vi v(s), vps(s+1);
    for(int &e : v)
      cin>>e;
    for(int i=0; i<s; i++)
      vps[i+1]=v[i]+vps[i];
    while(q--){
      int l, r, k;
      cin>>l>>r>>k;
      int f = (vps[l-1]+vps[s]-vps[r]) + (k * (r-l+1));
      cout<<(f%2 ? "YES" : "NO")<<(c==0 && q==0 ? "" : "\n");
    }
  }
}
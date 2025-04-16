#include <bits/stdc++.h>
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
  int n,m;
  while(cin>>n>>m && n && m){
    set<int> j;
    while(n--){
      int x;
      cin>>x;
      j.insert(x);
    }
    int c=0;
    while(m--){
      int x;
      cin>>x;
      if(j.count(x)) c++;
    }
    cout<<c<<'\n';
  }
  return 0;
}
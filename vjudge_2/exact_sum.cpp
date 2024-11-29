#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define bg begin()
#define en end()
#define sz(x) (int)x.size()
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int,int>>

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int S, T, first=1;
  while(cin>>S){
    if(!first) cout<<endl<<endl;
    first=0;
    vi a(S);
    vpi ans;
    for(int &i : a)
      cin>>i;
    cin>>T;
    sort(a.bg, a.en);
    for(int i=0; i<S; i++){
      auto it = lower_bound(a.bg+i+1, a.en, T-a[i])-a.bg;
      int it_v = *lower_bound(a.bg+i+1, a.en, T-a[i]);
      if(it<S && a[i]+it_v==T)
        ans.pb({a[i], it_v});
    }
    sort(ans.bg, ans.en, [](pair<int,int> p1, pair<int,int> p2){
      return abs(p1.f-p2.s) < abs(p2.f-p2.s);
    });
    cout<<"Peter should buy books whose prices are "<<ans[0].f<<" and "<<ans[0].s<<'.';
  }
}
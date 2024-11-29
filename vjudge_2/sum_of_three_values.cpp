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

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, t;
  cin>>n>>t;
  vi a(n), ans;
  for(int &e : a)
    cin>>e;
  int sum=0;
  for(int i=0; i<sz(a) && sum!=t; i++){
    ans.pb(i+1);
    sum=a[i];
    for(int j=i+1; j<sz(a) && sz(ans)<3; j++){
      if(sum+a[j]<=t){
        sum+=a[j];
        ans.pb(j+1);
      }
    }
    if(sz(ans)<3 || sum!=t){
      ans.clear();
      sum=0;
    }
  }
  if(sz(ans)==3 && sum==t)
    for(int i=0; i<sz(ans); i++)
      cout<<ans[i]<<(i==sz(ans) ? "" : " ");
  else
    cout<<"IMPOSSIBLE";
}
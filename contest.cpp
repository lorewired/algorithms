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
  int n,t=0;
  cin>>n;
  for(int i=2; i<=n; i++){
    int sr=sqrt(i);
    int c =0;
    for(int j=1; j<=sr; j++){
      if(j%sr)c++;
    }
    cout<<"test: "<<c<<'\n';
    if(c==9)t++;
  }
  cout<<t<<'\n';
  return 0;
}
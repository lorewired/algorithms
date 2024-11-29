#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, s;
  cin>>n;
  while(n--){
    cin>>s;
    vector<int> a(s);
    for(int &i : a) cin>>i;
    int ali=0, bob=0, l=0, r=s-1, max=0, eated=0;
    while(l<=r){
      eated++;
      if(ali<=bob)
        ali+=a[l++];
      else
        bob+=a[r--];
      if(ali==bob)
        max=eated;
    }
    cout<<max<<(!n?"":"\n");
  }
}
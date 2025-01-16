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
  int n,m,x;
  ifstream in("bcount.in");
  ofstream out("bcount.out");
  in>>n>>m;
  vector<int> v1(n),v2(n),v3(n);
  for(int i=0; i<n; i++){
    in>>x;
    switch(x){
    case 1: v1[i]=1; break;
    case 2: v2[i]=1; break;
    case 3: v3[i]=1; break; 
    }
  }
  for(int i=1;i<n;i++){
    v1[i]+=v1[i-1];
    v2[i]+=v2[i-1];
    v3[i]+=v3[i-1];
  }
  while(m--){
    int l,r;
    in>>l>>r;
    l--; r--;
    out<<(!l ? v1[r] : v1[r]-v1[l-1])<<' ';
    out<<(!l ? v2[r] : v2[r]-v2[l-1])<<' ';
    out<<(!l ? v3[r] : v3[r]-v3[l-1])<<'\n';
  }
  return 0;
}
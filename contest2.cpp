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

template<typename T,typename K>
void mptov(map<T, K> mp,vector<T> v) {for(const auto& i : mp) v.push_back(i);}

vi psum(vi v){
  vi a(sz(v)+1);
  for(int i=0; i<sz(v); i++)
    a[i+1]=v[i]+a[i];
  return a;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  vi v(n);
  for(int &e : v)
    cin>>e;
  vi ps=psum(v);
  for(int e : ps)
    cout<<e<<' ';
}
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

typedef struct{
  string n;
  int a, h;
  float w;
} reindeer;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int x, t, m;
  cin>>x;
  while(x--){
    cin>>t>>m;
    vector<reindeer> v;
    while(t--){
      reindeer r;
      cin>>r.n>>r.a>>r.h>>r.w;
      v.pb(r);
    }
    sort(v.bg, v.en, [](reindeer r1, reindeer r2){
      if(r2.w<r1.w)
        return r1.w>r2.w;
      if(r1.w==r2.w)
        return r1.a>r2.a;
      if(r1.w==r2.w && r1.a==r2.a)
        return r1.h>r2.h;
      return r1.n>r2.n;
    });
    cout<<"CENARIO {"<<x+1<<"}"<<endl;
    for(int i=0; i<m; i++)
      cout<<i+1<<" - "<<v[i].n<<endl;
  }
};
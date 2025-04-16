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
  int n,sum=0,t=0;
  cin>>n;
  priority_queue<int,vector<int>> pq;
  while(n--){
    int x;
    cin>>x;
    pq.push(x);
  }
  while(!pq.empty()){
    //if(sum+pq.top()>=0){
    //  sum+=pq.top();
    //  t++;
    //}
    cout<<pq.top()<<' ';
    pq.pop();
  }
  cout<<t<<'\n';
  return 0;
}
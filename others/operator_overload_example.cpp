#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
using namespace std;

typedef struct {
  int toggle = 0;
  bool operator() (const int a, const int b) {
    if (toggle) {
      toggle--;
      return a < b;
    }
    toggle++;
    return a > b;
  }
} test;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int a[] {20, 50, 10, 100, 80};
  set<int, test> st;
  //set<int, greater<int>> st2;
  for (int i : a) st.insert(i);
  for (auto it : st) cout << it << '\n';
  return 0;
}
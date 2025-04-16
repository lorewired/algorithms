#include <bits/stdc++.h>
#define ll long long
#define inf INT_MAX
const int mod = 1e9+7;
using namespace std;

vector<vector<int>> dp;
vector<int> dice;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i=1; i<=6; i++) dice.push_back(i);
  dp.assign(6, vector());
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

signed main() {
  int x, N;
  cin >> x;
  vector<int> even, odd;
  while (x--) {
    cin >> N;
    if (N % 2 == 0) even.push_back(N);
    else odd.push_back(N);
  }
  sort(even.begin(), even.end());
  sort(odd.begin(), odd.end(), [] (int n1, int n2) { return n1 > n2; });
  for (int i = 0; i < even.size(); i++)
    cout << even[i] << '\n';
  for (int i = 0; i < odd.size(); i++)
    cout << odd[i] << '\n';
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

set<int> solve(vector<int> n1, vector<int> n2) {
    set<int> s1, s2;
    for (int i : n1) s1.insert(i);
    for (int i : n2) s2.insert(i);
    set<int> ans;
    for (int i : n1) if (s2.count(i)) ans.insert(i);
    return ans;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    vector<int> n1 = {1, 2, 2, 1}, n2 = {2, 2   };
    set<int> ans = solve(n1, n2);
    cout << '[';
    int i = 0, sz = ans.size();
    for (auto &it : ans) {
        cout << (!i?"":", ") << it;
        i++;
    }
    cout << ']';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf LLONG_MAX
#define pb push_back
#define all(v) v.begin(), v.end()
#define lb lower_bound
#define ub upper_bound
typedef pair<int, int> pi;
typedef pair<int, pi> pipi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int n;
    cin >> n;
    vi v(n), ans(n);
    for(int &i : v) cin >> i;
    stack<int> st;
    for(int i=n-1; i>=0; i--) {
        ans[i] = st.size();
        while(st.size() && st.top() <= v[i])
            st.pop();
        st.push(v[i]);
    }
    for(int i : ans) cout << i << ' ';
    return 0;
}
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
    while(cin >> n && n) {
        vi v(n), l(n), r(n);
        for(int &i : v) cin >> i;
        stack<int> s1, s2;
        for(int i=0; i<n; i++) {
            while(s1.size() && v[i] <= v[s1.top()]) s1.pop();
            l[i] = s1.size() ? s1.top() : -1;
            s1.push(i);
            
            while(s2.size() && v[n-i-1] <= v[s2.top()]) s2.pop();
            r[n-i-1] = s2.size() ? s2.top() : n;
            s2.push(n-i-1);
        }
        int g = 0;
        for(int i=0; i<n; i++) g = max(g, v[i]*(r[i]-l[i]-1));
        cout << g << '\n';
    }
    return 0;
}
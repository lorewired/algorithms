#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;

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
    int n, m;
    cin >> n >> m;
    ord_set<pi> os;
    vi v;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        os.insert({x, i});
        v.pb(x);
    }
    while(m--) {
        char ty; int a, b;
        cin >> ty >> a >> b;
        if(ty == '?') {
            int r = os.order_of_key({b+1, -inf});
            int l = os.order_of_key({a, -inf});
            cout << r-l << '\n';
        } else {
            a--;
            auto itr = os.find({v[a], a});
            os.erase(itr);
            os.insert({v[a]=b, a});
        }
    }
    return 0;
}
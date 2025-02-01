#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <class T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;
#define int long long

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int A[] = {1, 7, 8, 5, 11};
    int a = 1, b = 11;
    ord_set<int> s;
    for(int i=0; i<4; i++) {
        s.insert(A[i]);
    }
    int bb = s.order_of_key(b);
    int aa = s.order_of_key(a+1);
    cout << bb << ' ' << aa << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

vector<vector<pair<int, pair<int, int>>>> adj;
vector<vector<int>> dist;
int n, m;

void dijkstra() {
    int ci[] = {-1, 0, 1, 0}, cj[] = {0, 1, 0, -1};
    set<pair<int, pair<int, int>>> st;
    st.insert({0, {0, 0}});
    dist[0][0] = adj[0][0].first;

    while(st.size()) {
        auto cur = *st.begin();
        int cur_w = cur.first, cur_i = cur.second.first, cur_j = cur.second.second;
        st.erase(st.begin());
        for(int i=0; i<4; i++) {
            int ii = cur.second.first + ci[i];
            int jj = cur.second.second + cj[i];
            if(ii>=0 && ii<n && jj>=0 && jj<m) {
                int w = adj[ii][jj].first;
                if(dist[cur_i][cur_j] + w < dist[ii][jj]) {
                    st.erase({w, {ii, jj}});
                    dist[ii][jj] = dist[cur_i][cur_j] + w;
                    st.insert({dist[ii][jj], {ii, jj}});
                }
            }
        }
    }

    cout << dist[n-1][m-1] << '\n';
}

void solve() {
    cin >> n >> m;
    adj.assign(n, vector<pair<int, pair<int, int>>>(m));
    dist.assign(n, vector<int>(m, LLONG_MAX));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int x; cin >> x;
            adj[i][j] = {x, {i, j}};
        }
    }
    dijkstra();
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--)
        solve();
    return 0;
}
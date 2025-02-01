#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

using pii = pair<int, int>;
vector<vector<int>> dist, vis;

int n, m, ci[] = {-1, 0, 1, 0}, cj[] = {0, 1, 0 ,-1};

int bfs(pii JOE, vector<pii> IN_FIRE) {
    queue<pair<pii, vector<pii>>> q;
    q.push({JOE, IN_FIRE});
    dist[JOE.first][JOE.second] = 1;
    vis[JOE.first][JOE.second] = 1;

    int ans = 0;
    while(q.size()) {
        pair<pii, vector<pii>> cur = q.front();
        pii joe = cur.first;
        q.pop();

        if(joe.first == 0 || joe.first == n-1 || joe.second == 0 || joe.second == m-1) {
            ans = dist[joe.first][joe.second];
            break;
        }

        vector<pii> cur_in_fire;
        for(pii fire : cur.second) {
            for (int k = 0; k < 4; k++) {
                int ii = fire.first + ci[k], jj = fire.second + cj[k];
                if (ii >= 0 && ii < n && jj >= 0 && jj < m && !vis[ii][jj]) {
                    vis[ii][jj] = 1;
                    cur_in_fire.push_back({ii, jj});
                }
            }
        }
        if(cur_in_fire.size()) q.push({joe, cur_in_fire});

        for (int k = 0; k < 4; k++) {
            int ii = joe.first + ci[k], jj = joe.second + cj[k];
            if (ii >= 0 && ii < n && jj >= 0 && jj < m && !vis[ii][jj]) {
                vis[ii][jj] = 1;
                dist[ii][jj] = dist[joe.first][joe.second] + 1;
                q.push({{ii, jj}, cur.second});
            }
        }
    }

    return ans;
}

void solve() {
    cin >> n >> m;
    dist.assign(n, vector<int>(m, -1));
    vis.assign(n, vector<int>(m, 0));
    vector<pii> in_fire;
    pii joe;
    for(int i=0 ; i<n; i++) {
        for(int j=0 ; j<m; j++) {
            char c;
            cin >> c;
            if(c == 'F' || c == '#') {
                vis[i][j] = 1;
                if(c == 'F') in_fire.push_back({i, j});
            }
            if(c == 'J') joe = {i, j};
        }
    }
    int ans = bfs(joe, in_fire);
    cout << (!ans ? "IMPOSSIBLE" : to_string(ans)) << '\n';
}


signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--)
       solve();
    return 0;
}
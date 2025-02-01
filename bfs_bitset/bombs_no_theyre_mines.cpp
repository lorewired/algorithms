#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

using pi = pair<int,int>;
vector<vector<int>> dist, vis;
int n, m, ci4[] = {-1, 0, 1, 0}, cj4[] = {0, 1, 0, -1};

int bfs(pi start, pi end) {
    queue<pi> q;
    q.push(start);
    vis[start.first][start.second] = 1;
    dist[start.first][start.second] = 0;

    while (q.size()) {
        auto [i,j] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ii = i + ci4[k], jj = j + cj4[k];
            if (ii>=0 && ii<n && jj>=0 && jj<m && dist[ii][jj] == -1 && !vis[ii][jj]) {
                q.push({ii,jj});
                vis[ii][jj] = 1;
                dist[ii][jj] = dist[i][j] + 1;
            }
        }
    }

    return dist[end.first][end.second];
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int rows;
    while(cin >> n >> m && n && m) {
        dist.assign(n, vector<int>(m, -1));
        vis.assign(n, vector<int>(m, 0));
        cin >> rows;
        while(rows--) {
            int r, qj;
            cin >> r >> qj;
            while(qj--) {
                int x; cin >> x;
                vis[r][x] = 1;
            }
        }
        int s1, s2, e1, e2;
        cin >> s1 >> s2 >> e1 >> e2;
        pi start = {s1,s2}, end = {e1, e2};
        int ans = bfs(start, end);
        cout<<(ans == -1 ? 0 : ans)<<'\n';
    }
    return 0;
}
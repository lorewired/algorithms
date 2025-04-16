#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

using vvi = vector<vector<int>>;
using pii = pair<int, int>;

const int ci8[] = {-1,0,1,0,-1,-1,1,1}, cj8[] = {0,1,0,-1,-1,1,-1,1};

int bfs(vvi& dist, vvi& vis, pii start, pii end) {
    queue<pii> q;
    q.push(start);
    vis[start.first][start.second] = 1;
    dist[start.first][start.second] = 0;


    while(q.size()) {
        pii cur = q.front();
        q.pop();

        for(int k=0; k<8; k++) {
            int ii = cur.first + ci8[k], jj = cur.second + cj8[k];
            if(ii>=0 && ii<8 && jj>=0 && jj<8 && !vis[ii][jj]) {
                q.push({ii, jj});
                vis[ii][jj] = 1;
                dist[ii][jj] = dist[cur.first][cur.second] + 1;
            }
        }
    }

    return dist[end.first][end.second];
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    pii start, end, c;
    int tt = 1;
    while(cin >> start.first >> start.second >> end.first >> end.second >> c.first >> c.second) {
        start.first--; start.second--; end.first--; end.second--; c.first--; c.second--;
        vvi dist(8, vector<int>(8, -1)), vis(8, vector<int>(8, 0));
        vis[c.first][c.second] = 1;
        int ans = bfs(dist, vis, start, end);
        cout << "Case " << tt++ << ": " << ans << '\n';
    }
    return 0;
}
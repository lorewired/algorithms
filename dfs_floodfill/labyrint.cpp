#include <bits/stdc++.h>
#define import <ElPsyKongroo>
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
using namespace std;

const int ci[] = {-1, 0, 1, 0};
const int cj[] = {0, 1, 0, -1};
const char dir[] = {'U', 'R', 'D', 'L'};

using pii = pair<int,int>;

vector<vector<char>> a;
vector<vector<int>> dist;
string path;
int n, m;

void find_path(pii A, pii B) {
    queue<pii> adjs;
    adjs.push(B);
    dist[B.first][B.second] = 0;
    vector<vector<pii>> parents(n, vector<pii>(m, {-1, -1}));

    while (!adjs.empty()) {
        auto [i, j] = adjs.front();
        adjs.pop();

        for (int k = 0; k < 4; k++) {
            int ii = i + ci[k];
            int jj = j + cj[k];
            if (ii >= 0 && ii < n && jj >= 0 && jj < m && a[ii][jj] != '#' && dist[ii][jj] == -1) {
                dist[ii][jj] = dist[i][j] + 1;
                parents[ii][jj] = {i, j};
                adjs.push({ii, jj});
            }
        }
    }

    pii cur = A;
    if (dist[cur.first][cur.second] != -1) {
        while (cur != B) {
            auto [pi, pj] = parents[cur.first][cur.second];
            for (int k = 0; k < 4; k++) {
                if (cur.first + ci[k] == pi && cur.second + cj[k] == pj) {
                    path += dir[k];
                    break;
                }
            }
            cur = {pi, pj};
        }
    }
}

signed main() {
    io;
    cin >> n >> m;
    a.resize(n, vector<char>(m));
    dist.resize(n, vector<int>(m, -1));
    pii A, B;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                A.first = i;
                A.second = j;
            }
            if (a[i][j] == 'B') {
                B.first = i;
                B.second = j;
            }
        }
    }
    find_path(A, B);
    if (path.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n" << path.size() << '\n' << path << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
#define import <ElPsyKongroo>
#define io ios_base::sync_with_stdio(false);
#define ll long long
using namespace std;

const int ci[] = {-1, 0, 1, 0};
const int cj[] = {0, 1, 0, -1 };
const char dir[] = {'U', 'R', 'D', 'L'};

vector<vector<string>> a;
vector<vector<bool>> vis;
vector<string> paths;
int n, m;

void setpaths(int i, int j, string p) {
    if (a[i][j] == "A") {
        paths.push_back(p);
        return;
    }
    vis[i][j] = true;
    a[i][j] = to_string(p.size());
    bool other = false;
    for (int k = 0; k < 4; k++) {
        int ii = i + ci[k];
        int jj = j + cj[k];
        if (ii >= 0 &&
            ii < n &&
            jj >= 0 &&
            jj < m &&
            !vis[ii][jj] &&
            a[ii][jj] != "#")
        {
            if (other) p.pop_back();
            p += dir[k];
            other = true;
            setpaths(ii, jj, p);
        }
    }
}

signed main() {
    io;
    cin >> n >> m;
    a.resize(n, vector<string>(m)); vis.resize(n, vector<bool>(m, 0));
    int x, y, x2, y2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = c;
            if (a[i][j] == "A") {
                x = i; y = j;
            }
            if (a[i][j] == "B") {
                x2 = i; y2 = j;
            }
        }
    }
    setpaths(x2, y2, "");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
    return 0;
} 
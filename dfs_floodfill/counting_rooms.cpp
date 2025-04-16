#include <bits/stdc++.h>
#define int long long
#define IOS \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr)
using namespace std;

vector<vector<char>> a;
int n, m, c = 0;

const int ci[] {0, -1, 0, 1};
const int cj[] {-1, 0, 1, 0};

void ff(int i, int j) {
    a[i][j] = '#';
    for (int k = 0; k < 4; k++) {
        int ii = i + ci[k];
        int jj = j + cj[k];
        if (ii >= 0 && ii < n && jj >= 0 && jj < m && a[ii][jj] == '.')
            ff(ii, jj);
    }
}

int32_t main()
{
    IOS;
    cin >> n >> m;
    a = vector<vector<char>>(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') {
                ff(i, j);
                c++;
            }
        }
    }
    cout << c << '\n';
    return 0;
}
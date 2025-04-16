#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    while (cin >> n && n != 0) {
        int end = 0;
        while (!end) {
            stack<int> s;
            vector<int> vec, res;
            for (int i = 0; i < n && !end; i++) {
                int x;
                cin >> x;
                if (x == 0)
                    end = 1;
                else
                    vec.push_back(x);
            }
            if (!end) {
                int target = 0;
                for (int i = 1; i <= n;) {
                    if (!s.empty() && s.top() == vec[target]) {
                        res.push_back(s.top());
                        s.pop();
                        target++;
                    } else {
                        if (i != vec[target])
                            s.push(i);
                        else {
                            res.push_back(i);
                            target++;
                        }
                        i++;
                    }
                }
                while (!s.empty()) {
                    res.push_back(s.top());
                    s.pop();
                }
                bool pass = true;
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i] != res[i])
                        pass = false;
                }
                cout << (pass ? "Yes" : "No") << '\n';
            }
        }
        cout << '\n';
    }
}
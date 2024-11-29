#include <bits/stdc++.h>
using namespace std;

signed main() {
    string S;
    map<char, float> mp {{'W', 1.0},{'H', 1.0/2},{'Q', 1.0/4},{'E', 1.0/8},{'S', 1.0/16},{'T', 1./32},{'X', 1.0/64},};
    while (cin >> S && S[0] != '*') {
        int T = 0;
        string tmp;
        for (char c : S) {
            if (c != '/')
                tmp += c;
            else {
                float T2 = 0;
                for (char c2 : tmp)
                    T2 += mp[c2];
                T += T2 == 1.0 ? T2 : 0;
                tmp = "";
            }
        }
        cout << T << '\n';
    }
    return 0;
}
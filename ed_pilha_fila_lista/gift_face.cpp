#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool valid(string& str, string& str2) {
    for (int i = 0; i < str2.size(); i++)
        if (str[i] != str2[str2.size() - (i+1)])
            return false;
    return true;
}

signed main() {
    int n, cont = 0;
    cin >> n;
    cin.ignore();
    stack<string> s;
    for (int i = 0; i < n; i++) {
        if (s.empty())
            s.push("F A C E");
        string str;
        getline(cin, str);
        if (!s.empty() && valid(str, s.top())) {
            s.pop();
            cont++;
        }
        else s.push(str);
    }
    cout << cont << '\n';
    return 0;
}
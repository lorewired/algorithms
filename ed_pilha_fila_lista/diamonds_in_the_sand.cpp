#include <iostream>
#include <string>
#include <stack>
using namespace std;

signed main() {
    int x;
    cin >> x;
    while (x--) {
        string str;
        cin >> str;
        stack<char> p;
        int cont = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '<')
                p.push(str[i]);
            else
                if (!p.empty() && str[i] == '>') {
                    ++cont;
                    p.pop();
                }
        }
        cout << cont << '\n';
    }
    return 0;
}
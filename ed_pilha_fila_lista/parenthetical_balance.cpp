#include <iostream>
#include <string>
#include <stack>
using namespace std;

signed main() {
    string str;
    while (cin >> str) {
        stack<char> p;
        bool correct = false;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '(')
                p.push(str[i]);
            else
                if (str[i] == ')') {
                    if (!p.empty() && p.top() == '(')
                        p.pop();
                    else
                        p.push(str[i]);
                }
        }
        cout << (p.empty() ? "correct" : "incorrect") << '\n';
    }
    return 0;
}
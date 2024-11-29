#include <bits/stdc++.h>
using namespace std;

void view_names(vector<string>& v) {
    for (const string n : v)
        cout << n << '\n';
}
void sort_names(vector<string>* v) {
    sort(v->begin(), v->end(), [] (string n1, string n2) {
        return n1 < n2;
    });
}
signed main() {
    map<string, int> m;
    string name, vote, prev, prev_def, habay_friend;
    int i = 0, min_size = 0;
    vector<string> names_yes, names_no;
    while (cin >> name && name != "FIM") {
        cin >> vote;
        if (vote == "YES") {
            if (m.find(name) == m.end()) {
                names_yes.push_back(name);
                m[name] = i++;
            }
            if (name.size() > min_size)
                min_size = name.size();
        } else {
            if (m.find(name) == m.end())
                names_no.push_back(name);
            m[name] = -1;
        }
    }
    for (const auto& p : m) {
        if (p.first.size() == min_size)
            if (prev == "") {
                prev = p.first;
                habay_friend = p.first;
            }
            else {
                habay_friend = p.first < prev ? p.first : prev;
                prev = p.first;
            }   
    }
    sort_names(&names_yes);
    sort_names(&names_no);
    view_names(names_yes);
    view_names(names_no);
    cout << "\nAmigo do Habay:\n" << habay_friend << '\n';
    return 0;
}
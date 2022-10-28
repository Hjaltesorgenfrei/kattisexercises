#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<string> names;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    names.resize(n);
    for (int i = 0; i < n; i++) cin >> names[i];
    bool sorted = true;
    for (int i = 1; i < n && sorted; i++) {
        auto& a = names[i - 1];
        auto& b = names[i];
        if (a.compare(b)) {
            cout << a << " " << b << endl;
            
            sorted = false;
        }
    }

    cout << (sorted ? "yes" : "no") << endl;
}

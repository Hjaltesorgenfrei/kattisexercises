#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int s = 1, a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s += --a;
    }
    cout << s << "\n";
}

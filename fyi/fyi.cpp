#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int a;
    cin >> a;
    cout << ((a / 10000) == 555) << "\n";
}

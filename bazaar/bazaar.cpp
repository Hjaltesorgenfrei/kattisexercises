#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long n, bonus = 0, ap = 0, bp = 0;
vector<long long> a;
vector<long long> b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n; 
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());
    for (int i = 0; i < n; i++) {
        ap += bonus++ + a[i];
        bp += bonus++ + b[i];
    }
    cout << ap - bp << endl;
}

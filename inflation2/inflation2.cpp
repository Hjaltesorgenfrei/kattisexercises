#include <iostream>
#include <unordered_map>
#include <string>

typedef long long LL;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 
    int n, q;
    cin >> n;
    LL sum = 0;
    unordered_map<LL, int> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        m[a] = m[a] + 1;
        sum += a;
    }
    LL inflation = 0;
    cin >> q;
    LL a, b;
    for (int i = 0; i < q; i++) {
        cin.get();
        if(cin.get() == 'S') {
            cin.ignore(3);
            cin >> a >> b;
            if (a != b) {
                int count = m[a - inflation];
                m[a - inflation] = 0;
                m[b - inflation] += count;
                sum += (b - a) * count;
            }
        }
        else {
            cin.ignore(9);
            cin >> a;
            inflation += a;
            sum += a * n;
        }
        cout << sum << "\n";
    }
}

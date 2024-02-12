#include <iostream>
// dont work :(
using namespace std;

int N, K;

bool reached[10] = {false};

inline int wrap(int n, bool up) {
    return ((n + (1 * up) - (1 * !up)) % K);
}

void reverse(int p, int n, bool up) {
    cout << p << " " << n << " " << up << " " << endl;
    if (n == 0) {
        reached[wrap(p, up)] = true;
        cout << wrap(p, up) << "?\n";
        return;
    }
    reverse(p, n - 1, !up);  // Another card by same player
    if (up && p < K - 1) {
        reverse(wrap(p, true), n - 1, true);
    } else if (p > 1) {
        reverse(wrap(p, false), n - 1, false);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> K >> N;
    if (N == 0 || N == 2) {  // Base case
        cout << "NO\n";
        return 0;
    }
    if (K == 2 || N == 1) {  // Base case
        cout << "YES\n";
        return 0;
    }
    reverse(1, N - 1, false);
    if (!reached[0]) {
        cout << "NO\n";
        return 0;
    }
    int count = 0;
    for (int i = 0; i < K; i++) {
        count += reached[i];
    }
    cout << ((count == 1) ? "YES\n" : "MAYBE\n");
}

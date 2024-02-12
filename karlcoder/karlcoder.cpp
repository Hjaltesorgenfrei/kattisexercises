#include <iostream>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long N = 1, min = 1, max = LLONG_MAX;

    int answer;
    while (min + 1 != max) {
        cout << "buf[" << N << "]" << endl;
        if (cin.peek() == 'S') {
            break;
        }
        cin >> answer;
        if (answer) {
            min = N;
            N = max == LLONG_MAX ? min * 2 : min + (max - min) / 2;
        } else {
            max = N;
            N = min + (max - min) / 2;
        }
    }

    cout << "strlen(buf) = " << max << endl;
}

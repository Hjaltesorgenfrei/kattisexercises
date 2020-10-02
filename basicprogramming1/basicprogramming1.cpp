#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A;
char chars[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    A.resize(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    long sum = 0;
    vector<bool> visited(n, false);
    int visit = 0;
    switch(t){
        case 1:
            cout << "7" << endl;
            break;
        case 2:
            if (A[0] > A[1]) cout << "Bigger" << endl;
            else if (A[0] == A[1])  cout << "Equal" << endl;
            else  cout << "Smaller" << endl;
            break;
        case 3:
            sort(A.begin(), A.begin()+3);
            cout << A[1] << endl;
            break;
        case 4:
            for (const auto & v : A) {
                sum += v;
            }
            cout << sum << endl;
            break;
        case 5:
            for (const auto & v : A) {
                if (v % 2 == 0) sum += v;
            }
            cout << sum << endl;
            break;
        case 6:
            for (const auto & v: A) {
                cout << chars[v%26];
            }
            cout << endl;
            break;
        case 7:
            while(true) {
                visited[visit] = true;
                visit = A[visit];
                if (visit >= n || visit < 0) {
                    cout << "Out" << endl;
                    break;
                }
                if (visit == n-1) {
                    cout << "Done" << endl;
                    break;
                }
                if (visited[visit]) {
                    cout << "Cyclic" << endl;
                    break;
                }
            }
            break;
        default:
            cout << "not done" << endl;
    }
}
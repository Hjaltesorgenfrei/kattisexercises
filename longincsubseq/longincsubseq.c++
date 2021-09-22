#include <iostream>
#include <string>
#include <vector>

using namespace std;

int seq[100000];

void longincsubseq(int n) {
    vector<vector<int>> dp(2, vector<int>(n + 1, -1));
    dp[0][0] = 0;
    for(int i = 1; i < n; i++) {
        int row = i % 2;
        int num = seq[i - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    while(cin >> n) {
        for(int i = 0; i < n; i++) {
            cin >> seq[i];
        }
    }
}

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

inline int solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> d(n);
    int b;
    for (int i = 0; i < n; i++) {
        cin >> d[i].first >> d[i].second; 
        d[i].second = -d[i].second;
    }
    sort(d.begin(), d.end());

    vector<int> heights;
    heights.emplace_back(d[0].second);
    for(int i = 1; i < d.size(); i++){
        int h = d[i].second;
        auto l = upper_bound(heights.begin(), heights.end(), h);
        if (l == heights.end()) heights.emplace_back(h);
        else *l = h;
    }
    return heights.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) cout << solve() << "\n";
}

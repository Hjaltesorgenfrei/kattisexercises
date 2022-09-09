#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

namespace Suffix { 
    const int N = 200001;
    int sa[N], rank[N], lcp[N], gap, S;
    bool cmp(int x, int y) {
        if(rank[x] != rank[y])
            return rank[x] < rank[y];
        x += gap, y += gap;
        return (x < S && y < S)? rank[x] < rank[y]: x > y;
    }
    void Sa_build(const string &s) {
        S = s.size();
        int tmp[N] = {0};
        for(int i = 0;i < S;++i)
            rank[i] = s[i],
            sa[i] = i;
        for(gap = 1;;gap <<= 1) {
            sort(sa, sa + S, cmp);
            for(int i = 1;i < S;++i)
                tmp[i] = tmp[i - 1] + cmp(sa[i - 1], sa[i]);
            for(int i = 0;i < S;++i)
                rank[sa[i]] = tmp[i];
            if(tmp[S - 1] == S - 1)
                break;
        }
    }
    void Lcp_build(const string &s) {
        for(int i = 0, k = 0;i < S;++i, --k)
            if(rank[i] != S - 1) {
                k = max(k, 0);
                while(s[i + k] == s[sa[rank[i] + 1] + k])
                    ++k;
                lcp[rank[i]] = k;
            }
            else
                k = 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string b;
    int n, v;
    cin >> n;
    cin >> b;
    Suffix::Sa_build(b);
    Suffix::Lcp_build(b);
    
    cout << *max_element(Suffix::lcp, Suffix::lcp+n) << "\n";
}
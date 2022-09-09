#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s1, s2;  
    cin >> s1 >> s2;
    int diff = 0;
    int pos1, pos2;
    for(int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            diff += 1; 
            pos1 = pos2;
            pos2 = i;
        }
    }

    if (diff == 1 ) {
        cout << "0\n";
        return 0;
    }

    if(diff == 2) {
        if (s1[pos1] == s2[pos2] && s1[pos2] == s2[pos1] && (pos1 == 0 || pos2 == 0)) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
        return 0;
    }

    for(int A = 0; A <= s1.size(); A++) {
        for (int B = 0; A + B <= s1.size(); B++) {
            for (int C = 0; A + B + C <= s1.size(); C ++) {
                if (s1.size() > 100 && A != C) continue;
                int D = s1.size() - (A + B + C);
                int part_1 = !(strncmp(s1.data(), s2.data() + C + B, A));
                int part_2 = !(strncmp(s1.data() + A, s2.data() + C, B));
                int part_3 = !(strncmp(s1.data() + A + B, s2.data(), C));
                int part_4 = !(strncmp(s1.data() + A + B + C, s2.data() + C + B + A, D));

                if (part_1 && part_2 && part_3 && part_4) {
                    cout << "1\n";
                    return 0; 
                }
            }
        }
    }
    cout << "0\n";
    return 0;
}
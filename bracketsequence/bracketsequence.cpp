#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

// Dont create a vector of strings, it copies the string. Just view it
vector<string> split(string& s, const string& delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<ll> openBracketDistances(1, 0);
    vector<ll> values;
    openBracketDistances.reserve(n);
    values.reserve(n);
    string buf;
    getline(cin, buf);
    getline(cin, buf);
    auto res = split(buf, " ");
    for (const auto& s : res) {
        switch(s[0]) {
            case '(':
                openBracketDistances.push_back(0);
                break;
            case ')': {
                auto distance = openBracketDistances.back();
                openBracketDistances.pop_back();
                ll sum = 0;
                if (openBracketDistances.size() % 2 == 0) {
                    for (int i = 0; i < distance; i++) {
                        sum = (sum + values.back()) % 1000000007;
                        values.pop_back();
                    }
                } else {
                    sum = values.back();
                    values.pop_back();
                    for (int i = 1; i < distance; i++) {
                        sum = (sum * values.back()) % 1000000007;
                        values.pop_back();
                    }
                }
                // cout << distance << " " << sum << "\n";
                values.push_back(sum);
                openBracketDistances.back()++;
            }
                
                break;
            default:
                values.push_back(stoll(s));
                openBracketDistances.back()++;
                break;
        }
    }

    ll sum = 0;
    for (const auto a : values) {
        sum = (sum + a) % 1000000007;
    }
    cout << sum << "\n";
}

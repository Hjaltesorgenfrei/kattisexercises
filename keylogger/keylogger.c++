#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

unordered_map<string, char> m = {
    {"clank", 'a'},
    {"bong", 'b'},
    {"click", 'c'},
    {"tap", 'd'},
    {"poing", 'e'},
    {"clonk", 'f'},
    {"clack", 'g'},
    {"ping", 'h'},
    {"tip", 'i'},
    {"cloing", 'j'},
    {"tic", 'k'},
    {"cling", 'l'},
    {"bing", 'm'},
    {"pong", 'n'},
    {"clang", 'o'},
    {"pang", 'p'},
    {"clong", 'q'},
    {"tac", 'r'},
    {"boing", 's'},
    {"boink", 't'},
    {"cloink", 'u'},
    {"rattle", 'v'},
    {"clock", 'w'},
    {"toc", 'x'},
    {"clink", 'y'},
    {"tuc", 'z'},
    {"whack", '1'},
    {"bump", '2'},
    {"pop", '3'},
    {"dink", '4'},
    {"thumb", '5'},
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    bool caps = false, shift = false;
    vector<char> keys;
    cin >> n;
    string buf;
    for (int i = 0; i < n; i++) {
        cin >> buf;
        char c = m[buf];
        switch (c) {
            case '1':
                keys.push_back(' ');
                break;
            case '2':
                caps = !caps;
                break;
            case '3':
                if(keys.size())  keys.pop_back();
                break;
            case '4':
                shift = true;
                break;
            case '5':
                shift = false;
                break;
            default:
                if (shift ^ caps) c = toupper(c);
                keys.push_back(c);
                break;
        }
    }
    for(auto & c : keys) cout << c;
    cout << "\n";
}

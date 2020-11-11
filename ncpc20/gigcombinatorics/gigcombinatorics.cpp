#include <iostream>
#include <string>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    long ones = 0;
    long combinations = 0;
    long result = 0;
    long m = 1000000007;
    string buf;
    getline(cin, buf);
    getline(cin, buf);

    for(int i = 0; i < n * 2; i += 2){
        switch(buf[i]){
            case '1':
                ones++;
                continue;
            case '2':
                combinations *= 2;
                combinations += ones;
                while(combinations > m) combinations -= m;
                continue;
            case '3':
                result += combinations;
                while(result > m) result -= m;
                continue;
        }
    }

    cout << result;
}
#include <iostream>
#include <vector>

using namespace std;

const int memSize = 1000000;
vector<unsigned char> memory(memSize, 0);
int mem = memSize / 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    char buf;
    vector<char> program;
    while (cin >> buf && buf != '_') {
        switch (buf) {
            case '>':
            case '<':
            case '+':
            case '-':
            case '.':
            case '[':
            case ']':
                program.push_back(buf);
            default:
                break;
        }
    }
    vector<int> jumps(program.size(), -1);
    int pc = 0;
    while (pc < program.size()) {
        switch (program[pc]) {
            case '>':
                mem++;
                break;
            case '<':
                mem--;
                break;
            case '+':
                memory[mem] = (memory[mem] + 1);
                break;
            case '-':
                memory[mem] = (memory[mem] - 1);
                break;
            case '.':
                cout << memory[mem];
                break;
            case '[':
                if (!memory[mem]) {
                    if (jumps[pc] != -1) {
                        pc = jumps[pc];
                        break;
                    }
                    int start = pc;
                    int bracketCount = 1;
                    while(bracketCount) {
                        pc++;
                        if (pc < 0 || pc >= program.size()) return 0;
                        if (program[pc] == ']') bracketCount--;
                        if (program[pc] == '[') bracketCount++;
                    }
                    jumps[start] = pc; 
                }
                break;
            case ']':
                if (memory[mem]) {
                    if (jumps[pc] != -1) {
                        pc = jumps[pc];
                        break;
                    }
                    int start = pc;
                    int bracketCount = 1;
                    while(bracketCount) {
                        pc--;
                        if (pc < 0 || pc >= program.size()) return 0;
                        if (program[pc] == ']') bracketCount++;
                        if (program[pc] == '[') bracketCount--;
                    }
                    jumps[start] = pc; 
                }
                break;
        }
        pc++;
    }
}

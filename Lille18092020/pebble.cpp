#include <map>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

map<string, int> mov;

int numMoves(string cur, int moves){
    string temp;
    int maxV = moves;
    for(int i = 0; i < cur.size() - 2; i++){
        if(cur[i] == 'o' && cur[i + 1] == 'o' && cur[i + 2] == '-'){
            temp = cur.substr(0,i) + "--o" + cur.substr(i+3);
            if (mov.find(temp) == mov.end()){
                maxV = max(maxV, numMoves(temp, moves + 1));
            } else {
                maxV = max(mov[temp], maxV);
            }
        }
        if(cur[i] == '-' && cur[i + 1] == 'o' && cur[i + 2] == 'o'){
            temp = cur.substr(0,i) + "o--" + cur.substr(i+3);
            if (mov.find(temp) == mov.end()){
                maxV = max(maxV, numMoves(temp, moves + 1));
            } else {
                maxV = max(mov[temp], maxV);
            }
        }
    }
    mov[cur] = maxV;
    return maxV;
}

int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    string buf;
    getline(cin, buf);
    int v = 0;
    for (int i = 0; i < n; i++){    
        getline(cin, buf);
        v = count(buf.begin(), buf.end(), 'o');
        cout << v - numMoves(buf, 0) << endl;
    }
}
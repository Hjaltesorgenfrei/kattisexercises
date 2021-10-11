#include <iostream>
#include <vector>

#define SCALE 100

using namespace std;

struct Circle {
    int x;
    int y;
    int r;
};

int n;

Circle circles[10];

bool inside(int x, int y) {
    for (int i = 0; i < n; i++) {
        int xk = x - circles[i].x;
        int yk = y - circles[i].y;
        if ((xk * xk) + (yk * yk) <= circles[i].r) {
            return true;
        }
    }
    return false;
}

void printcircles() {
    for (int i = 0; i < n; i++) {
        cout << "(" << circles[i].x << ", " << circles[i].y << ", " << circles[i].r << ")\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int x, y, r;
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> r;
        x += 10; // So we move outside 0
        y += 10;
        x *= SCALE;        
        y *= SCALE;
        r *= SCALE;
        r *= r; 
        circles[i].x = x;
        circles[i].y = y;
        circles[i].r = r;
    }

    long long points = 0;
    for (int x = 0; x < (30 * SCALE); x++) {
        for (int y = 0; y < (30 * SCALE); y++) {
            points += inside(x, y);
        }
    }
    float scale = SCALE * 100;
    cout << points / scale << "\n";
}

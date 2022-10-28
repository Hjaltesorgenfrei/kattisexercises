#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct Point {
    int X;
    int Y;

    Point() : X(0), Y(0){};
    Point(const int& x, const int& y) : X(x), Y(y){};
    Point(const Point& other) {
        X = other.X;
        Y = other.Y;
    };

    Point& operator=(const Point& other) {
        X = other.X;
        Y = other.Y;
        return *this;
    };

    bool operator==(const Point& other) const {
        if (X == other.X && Y == other.Y)
            return true;
        return false;
    };

    bool operator<(const Point& other) {
        if (X < other.X)
            return true;
        else if (X == other.X && Y == other.Y)
            return true;

        return false;
    };

    // this could be moved in to std::hash<Point>::operator()
    size_t operator()(const Point& pointToHash) const noexcept {
        size_t hash = pointToHash.X + 10 * pointToHash.Y;
        return hash;
    };
};

enum Direction {
    Left,
    Right,
    Up,
    Down
};

Point move(Point p, Direction d) {
    switch (d) {
        case Left:
            return Point(p.X - 1, p.Y);
        case Right:
            return Point(p.X + 1, p.Y);
        case Up:
            return Point(p.X, p.Y + 1);
        case Down:
            return Point(p.X, p.Y - 1);
    }
    return Point();
}

void movedTo(Point p1, Direction direction, unordered_set<Point, Point>& scooters, bool robot = false) {
    auto scooter = scooters.find(p1);
    if (scooter != scooters.end()) {
        scooters.erase(scooter);
        movedTo(move(p1, direction), direction, scooters);
    }
    if (!robot) {
        scooters.insert(p1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    Point robot, depot;
    cin >> robot.X >> robot.Y >> depot.X >> depot.Y;
    unordered_set<Point, Point> scooters;
    for (int i = 0; i < n; i++) {
        Point scooter;
        cin >> scooter.X >> scooter.Y;
        scooters.insert(scooter);
    }

    while (!scooters.empty()) {
        auto scooter = scooters.begin();
        int x = scooter->X;
        int y = scooter->Y;

        // move into position vertically
        while (x != depot.X) {
            else if (robot.Y == y) {

            }
            else {
                Direction d = robot.Y < y ? Up : Down;
                robot = move(robot, d);
                movedTo(robot, d, scooters, true);
            }
        }
    }

    return 0;
}

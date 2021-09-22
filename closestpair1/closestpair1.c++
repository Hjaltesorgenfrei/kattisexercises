#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <iterator>

using namespace std;

typedef pair<double, double> Point;

int n;
vector<Point> points;

struct Result {
    double distance;
    double p1_x, p1_y, p2_x, p2_y;
    bool const operator <( const Result& rhs) const {
        return distance < rhs.distance;
    }
};

const inline Result distance_y(vector<Point>& points_y, int _p1, int _p2) {
    double x = points_y[_p1].first - points_y[_p2].first; 
    double y = points_y[_p1].second - points_y[_p2].second; 
    Result r = {
        .distance = sqrt((x * x) + (y * y)),
        .p1_x = points_y[_p1].first,
        .p1_y = points_y[_p1].second,
        .p2_x = points_y[_p2].first,
        .p2_y = points_y[_p2].second,
    };
    return r;
}

const inline Result distance_x(int _p1, int _p2) {
    double x = points[_p1].first - points[_p2].first; 
    double y = points[_p1].second - points[_p2].second; 
    Result r = {
        .distance = sqrt((x * x) + (y * y)),
        .p1_x = points[_p1].first,
        .p1_y = points[_p1].second,
        .p2_x = points[_p2].first,
        .p2_y = points[_p2].second,
    };
    return r;
}

Result closestpair(int start, int end){
    int length = end - start;
    if (length == 2) {
        return distance_x(start, start + 1);
    }
    if (length == 3) {
        return min({distance_x(start, start + 1), distance_x(start, start + 2), distance_x(start + 1, start + 2)});
    }
    int mid = start + (length / 2);
    Result min_distance = min(closestpair(start, mid), closestpair(mid, end));
    double line_x = points[mid].first;
    vector<Point> points_y;
    copy_if(
        points.begin() + start, 
        points.begin() + end, 
        back_inserter(points_y), 
        [&](Point p){return abs(p.first - line_x) <= min_distance.distance;});
    sort(points_y.begin(), points_y.end(), [](Point p1, Point p2) {return p1.second < p2.second;});
    int py = points_y.size();
    for(int i = 0; i < py; i++) {
        for(int j = i + 1; j < py && j < i + 8; j++) {
            min_distance = min(min_distance, distance_y(points_y, i, j)); //< --- Bug here
        }
    }
    return min_distance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (true) {
        cin >> n;   
        if (n == 0) break;
        points.resize(n);
        for (int i = 0; i < n; i++){
            cin >> points[i].first >> points[i].second;
        }
        sort(points.begin(), points.end());
        Result result = closestpair(0, n);
        cout << result.p1_x << " "<< result.p1_y << " "<< result.p2_x << " "<< result.p2_y << "\n";
    }
    
}

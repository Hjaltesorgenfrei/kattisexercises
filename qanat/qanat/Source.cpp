#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

float w, h, n;
float ratio;

float inline calculate_cost(float const tunnelX, float const length) {
	auto const tunnelHeight = tunnelX * ratio;
	return pow((tunnelHeight + length), 2) / 2;
}

float inline calculate_qanat(vector<float> wells) {
	auto sum = calculate_cost(0, wells[0]);
	for (unsigned int i = 0; i < wells.size() - 1; i++) {
		sum += calculate_cost(wells[i], wells[i + 1] - wells[i]);
	}
	sum += calculate_cost(wells[wells.size() - 1], w - wells[wells.size() - 1]);
	sum += calculate_cost(w, 0);
	return sum;
}

int main() {
	cin >> w >> h >> n;
	ratio = h / w;
	cout << calculate_qanat({ 3});
	return 0;
}
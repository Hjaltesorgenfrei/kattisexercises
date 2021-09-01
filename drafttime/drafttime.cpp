#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <string>
#include <functional>
#include <deque>

using namespace std;

struct Proposer {
    int partner;
    int proposed_count;
    vector<int> preferences;
};

struct Rejecter {
    int partner;
    vector<int> preferences;
};

vector<Proposer> proposers;
vector<Rejecter> rejecters;

void stable_match() {
    
}

int main() {

}
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
    int partner = -1;
    int proposed_count;
    
    // Index of preferences in sorted order
    vector<int> preferences;
    
    int next_proposal() {
        return preferences[proposed_count++];
    }
};

struct Rejecter {
    int partner = -1;

    // Rejecters preference of proposers, low value is better.
    // A given index in preference is occupied by that proposer.
    vector<int> preferences_values; 
};

vector<Proposer> proposers;
vector<Rejecter> rejecters;

bool proposals_left(int proposer_id) {
    auto proposer = proposers[proposer_id];
    return proposer.proposed_count >= proposer.preferences.size();
}

void marry(int proposer_id, int rejecter_id) {
    rejecters[rejecter_id].partner = proposer_id;
    proposers[proposer_id].partner = rejecter_id;
}

bool preferred(int proposer_id, int rejecter_id) {
    auto rejecter = rejecters[rejecter_id];
    int proposer_preference = rejecter.preferences_values[proposer_id];
    int old_preference = rejecter.preferences_values[rejecter.partner];
    return proposer_preference < old_preference;
}

bool stable_match() {
    deque<int> unmatched(proposers.size());
    for (int i = 0; i < unmatched.size(); i++) {
        unmatched[i] = i;
    }

    while (unmatched.size() && proposals_left(unmatched.front())) {
        int proposer_id = unmatched.front();
        unmatched.pop_front();
        auto proposer = proposers[proposer_id];
        int rejecter_id = proposer.next_proposal();
        auto rejecter = rejecters[rejecter_id];

        if (rejecter.partner == -1) { // No Marriage yet
            marry(proposer_id, rejecter_id);
        }
        else if (preferred(proposer_id, rejecter_id)) { // Preferred Marriage
            unmatched.push_back(rejecter.partner);
            proposers[rejecter.partner].partner = -1;
            marry(proposer_id, rejecter_id);
        }
        else { // No match found, try again
            unmatched.push_back(proposer_id);
        }
    }

    return unmatched.size() == 0; 
}

// Problem Specific

int main() {

}
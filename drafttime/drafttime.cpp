#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <string>
#include <functional>
#include <deque>
#include <algorithm>

using namespace std;

struct Proposer {
    int partner = -1;
    int proposed_count = 0;
    
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
    return proposer.proposed_count < proposer.preferences.size();
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
    deque<int> unmatched(proposers.size(), 0);
    for (int i = 0; i < proposers.size(); i++) {
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

int n, m, k;

void debug_print() {
    cout << "Proposers:\n";
    for (int i = 0; i < n; i++) {
        cout << i << " (" << proposers[i].partner << "): ";
        for (auto v : proposers[i].preferences) {
            cout << v << " "; 
        }
        cout << "\n";
    }

    cout << "\nRejecters:\n";
    for (int i = 0; i < k; i++) {
        cout << i << " (" << rejecters[i].partner << "): ";
        for (auto v : rejecters[i].preferences_values) {
            cout << v << " "; 
        }
        cout << "\n";
    }
}

unordered_map<string, int> team_mapping;
unordered_map<string, int> player_mapping;
vector<vector<string>> teams_unconverted;
vector<vector<int>> final_drafts;

int main() {
    cin >> n >> m >> k;
    proposers.resize(n);
    final_drafts.resize(n);
    rejecters.resize(k);
    string buf;
    teams_unconverted.resize(k);
    for (int i = 0; i < n; i++) {
        cin >> buf; 
        team_mapping[buf] = i;
        teams_unconverted[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> teams_unconverted[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        cin >> buf; 
        player_mapping[buf] = i;
        rejecters[i].preferences_values.resize(n);
        for (int j = 0; j < n; j++){
            cin >> buf;
            rejecters[i].preferences_values[team_mapping[buf]] = j;
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto player : teams_unconverted[i]) {
            proposers[i].preferences.push_back(player_mapping[player]);
        }
    }
    

    
    for (int i = 0; i < m; i++) {
        stable_match();
        debug_print();
        unordered_set<int> drafted;
        for(int j = 0; j < k; j++) {
            rejecters[j].partner = -1;
        }
        for(int j = 0; j < n; j++) {
            int draft_id = proposers[j].partner;
            drafted.emplace(draft_id);
            final_drafts[j].emplace_back(draft_id);
        }
        for(auto& team : proposers) {
            team.partner = -1;
            team.proposed_count = 0;
            team.preferences.erase(
                    remove_if(
                        team.preferences.begin(), 
                        team.preferences.end(), 
                        [drafted](int v) { return drafted.find(v) != drafted.end(); }
                    ),
                team.preferences.end()
                );
        }
    }
    

    

    return 0;
}
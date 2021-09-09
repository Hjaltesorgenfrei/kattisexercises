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

int n, m, k;

struct Player {
    int proposed_count = 0;
    
    // Index of preferences in sorted order
    vector<int> preferences;
    
    int next_proposal() {
        return preferences[proposed_count++];
    }
};

struct Team {
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> partners;

    // Rejecters preference of proposers, low value is better.
    // A given index in preference is occupied by that proposer.
    vector<int> preferences_values; 
};

vector<Player> players;
vector<Team> teams;

bool proposals_left(int proposer_id) {
    auto& proposer = players[proposer_id];
    return proposer.proposed_count < proposer.preferences.size();
}

void join(int proposer_id, int rejecter_id) {
    int pref = teams[rejecter_id].preferences_values[proposer_id];
    teams[rejecter_id].partners.push(make_pair(pref,proposer_id));
}

bool preferred(int proposer_id, int rejecter_id) {
    auto& rejecter = teams[rejecter_id];
    int proposer_preference = rejecter.preferences_values[proposer_id];
    int old_preference = rejecter.partners.top().first;
    return proposer_preference < old_preference;
}

bool stable_match() {
    deque<int> unmatched(players.size(), 0);
    for (int i = 0; i < players.size(); i++) {
        unmatched[i] = i;
    }

    while (unmatched.size() && proposals_left(unmatched.front())) {
        int proposer_id = unmatched.front();
        unmatched.pop_front();
        auto& proposer = players[proposer_id];
        int rejecter_id = proposer.next_proposal();
        auto& rejecter = teams[rejecter_id];

        if (rejecter.partners.size() < m) { // Not enough players yet
            join(proposer_id, rejecter_id);
        }
        else if (preferred(proposer_id, rejecter_id)) { // Preferred player
            unmatched.push_front(rejecter.partners.top().second);
            rejecter.partners.pop();
            join(proposer_id, rejecter_id);
        }
        else { // No match found, try again
            unmatched.push_front(proposer_id);
        }
    }

    return unmatched.size() == 0; 
}

unordered_map<string, int> team_mapping;
unordered_map<string, int> player_mapping;
vector<string> team_names;
vector<string> player_names;
vector<vector<string>> teams_unconverted;

int main() {
    cin >> n >> m >> k;
    teams.resize(n);
    team_names.resize(n);
    player_names.resize(k);
    players.resize(k);
    string buf;
    teams_unconverted.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> buf; 
        team_names[i] = buf;
        team_mapping[buf] = i;
        teams_unconverted[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> teams_unconverted[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        cin >> buf; 
        player_names[i] = buf;
        player_mapping[buf] = i;
        players[i].preferences.resize(n);
        for (int j = 0; j < n; j++){
            cin >> buf;
            players[i].preferences[j] = team_mapping[buf];
        }
    }
    for (int i = 0; i < n; i++) {
        teams[i].preferences_values.resize(k);
        for (int j = 0; j < teams_unconverted[i].size(); j++) {
            int player = player_mapping[teams_unconverted[i][j]];
            teams[i].preferences_values[player] = j;
        }
    }
    
    stable_match();
    
    for(int i = 0; i < n; i++) {
        cout << team_names[i] << " ";
        while(teams[i].partners.size()) {
            int player = teams[i].partners.top().second;
            teams[i].partners.pop();
            cout << player_names[player] << (teams[i].partners.size() ? " " : ""); 
        }
        cout << "\n";
    }

    return 0;
}
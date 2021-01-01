#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <unordered_set>

using namespace std;

struct road {
    int target;
    int length;
};

int cities_count;
int roads_count;
int initial_city;
int target_city;

int paths_count = 0;
int min_len = INT_MAX;
int max_team = 0;

int *teams;
list<road> *graph;
list<list<int>> paths;

void init_teams();
void init_graph();
void get_shortest_paths(int pos, int team, int len);

int main() {
    cin >> cities_count >> roads_count >> initial_city >> target_city;
    teams = new int[cities_count];
    graph = new list<road>[cities_count];
    init_teams();
    init_graph();
    // cout << endl;
    get_shortest_paths(initial_city, teams[initial_city], 0);
    cout << paths_count << " " << max_team;
    delete[] teams;
    delete[] graph;
}

void init_teams() {
    for (int i = 0; i < cities_count; i++) {
        cin >> teams[i];
    }
}

void init_graph() {
    for (int i = 0; i < roads_count; i++) {
        int c1, c2, l;
        cin >> c1 >> c2 >> l;
        graph[c1].push_back(road{c2, l});
        graph[c2].push_back(road{c1, l});
    }
}

unordered_set<int> iterated{};

ostream &operator<<(ostream &out, const unordered_set<int> set) {
    for (auto i = set.begin(); i != set.end(); i++) {
        out << *i << " ";
    }
    return out;
}

void get_shortest_paths(int pos, int team, int len) {
    iterated.insert(pos);
    if (pos == target_city) {
        if (len < min_len) {
            min_len = len;
            max_team = team;
            paths_count = 1;
        } else {
            max_team = max(max_team, team);
            paths_count++;
        }
        iterated.erase(pos);
        return;
    }

    for (auto i = graph[pos].begin(); i != graph[pos].end(); ++i) {
        if (!iterated.count(i->target) && len + i->length <= min_len) {
            get_shortest_paths(i->target, team + teams[i->target],
                               len + i->length);
        }
    }
    iterated.erase(pos);
}
#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct sign {
    int id;
    int time;
};

bool operator<(sign lhs, sign rhs) { return lhs.time < rhs.time; }

bool operator>(sign lhs, sign rhs) { return lhs.time > rhs.time; }

vector<string> students{};

sign first_in{-1, 3600 * 60 + 1};
sign last_out{-1, 0};

int gettime() {
    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    return h * 3600 + m * 60 + s;
}

void readsign() {
    string id_s;
    int id;
    int time_in, time_out;

    cin >> id_s;
    id = students.size();
    students.push_back(id_s);

    time_in = gettime();
    time_out = gettime();
    if (time_in < first_in.time) {
        first_in.time = time_in;
        first_in.id = id;
    }
    if (time_out > last_out.time) {
        last_out.time = time_out;
        last_out.id = id;
    }
}

int main() {
    int count;
    cin >> count;
    for (int i = 0; i < count; i++) {
        readsign();
    }
    cout << students[first_in.id] << " " << students[last_out.id] << endl;
}
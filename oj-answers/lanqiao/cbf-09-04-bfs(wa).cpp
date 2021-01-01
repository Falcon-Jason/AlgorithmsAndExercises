#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int times[110000] = {0};
queue<int> bfs;

void search(int n, int k) {
    bfs.push(0);
    while (!bfs.empty()) {
        int i = bfs.front();
        bfs.pop();
        if (i + 1 < n && times[i + 1] == 0) {
            bfs.push(i + 1);
            times[i + 1] = times[i] + 1;
        }
        if (i + k < n && times[i + k] == 0) {
            bfs.push(i + k);
            times[i + k] = times[i] + 1;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    search(n, k);
    int max_times = times[0];
    for (int i = 1; i < n; i++) {
        max_times = max(max_times, times[i]);
    }
    cout << max_times << endl;
}
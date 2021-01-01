#include <algorithm>
#include <iostream>
using namespace std;

int times[110000] = {0};

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        times[i] = i;
    }
    times[k] = 1;
    int max_times = k - 1;
    for (int i = k + 1; i < n; i++) {
        times[i] = min(times[i - 1], times[i - k]) + 1;
        max_times = max(max_times, times[i]);
    }
    cout << max_times << endl;
}
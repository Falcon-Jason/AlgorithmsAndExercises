#include <iostream>

using namespace std;
int main() {
    int count;
    cin >> count;
    long long *seq = new long long[count];
    for (int i = 0; i < count; i++) {
        cin >> seq[i];
    }

    long long cur_left = 0;
    long long max_left = 0, max_right = 0;
    long long cur_sum = 0;
    long long max_sum = -1;

    for (int i = 0; i < count; i++) {
        cur_sum += seq[i];
        if (cur_sum >= 0) {
            if (cur_sum > max_sum) {
                max_sum = cur_sum;
                max_right = i;
                if (max_left != cur_left) {
                    max_left = cur_left;
                }
            }
        } else {
            cur_left = i + 1;
            cur_sum = 0;
        }
    }
    if (max_sum < 0) {
        max_sum = 0;
        max_left = 0;
        max_right = count - 1;
    }

    cout << max_sum << " " << seq[max_left] << " " << seq[max_right] << endl;
    return 0;
}
#include <algorithm>
#include <iostream>

#define SIZE 100010

int maxScore = 0;
int score[SIZE] = {0};
int dpfunc[SIZE] = {0};
int step;

using namespace std;

inline int dp(int i) {
    return i >= 0 ? dpfunc[i] : 0;
}

int maxOnline[SIZE] = {0};
int dpMaxOnline() {
    for (int i = 0; i <= maxScore; i++) {
        dpfunc[i] = max(dp(i - 2 * step) + score[i], dp(i - step));
        maxOnline[i % step] = dpfunc[i];
    }
    int sum = 0;
    for (int i = 0; i <= maxScore; i++) {
        sum += maxOnline[i];
    }
    return sum;
}

int countScore() {
    int count = 0;
    for (int i = 0; i <= maxScore; i++) {
        if (score[i]) {
            count++;
        }
    }
    return count;
}

int main() {
    int size;
    cin >> size >> step;
    for (int i = 0; i < size; i++) {
        int s;
        cin >> s;
        score[s]++;
        maxScore = max(maxScore, s);
    }

    cout << (step == 0 ? countScore() : dpMaxOnline()) << endl;
}
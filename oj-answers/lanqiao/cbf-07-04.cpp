#include <iostream>

int tower[50][50];
using namespace std;
int robotCount[2];
int towerHeight;

void calcTowerHeight() {
    int totalSize = robotCount[0] + robotCount[1];
    int sum = 0;
    towerHeight = 0;
    while (sum < totalSize) {
        sum += towerHeight + 1;
        towerHeight++;
    }
}

void printTower() {
    for (int i = 0; i < towerHeight; i++) {
        for (int j = 0; j < towerHeight - i; j++) {
            cout << tower[i][j];
        }
        cout << endl;
    }
}

void printTowerBotton() {
    for (int i = 0; i < towerHeight; i++) {
        cout << tower[0][i];
    }
    cout << endl;
}

bool isAvailableTower() {
    // printTowerBotton();
    int robotCount[2] = {::robotCount[0], ::robotCount[1]};
    for (int i = 1; i < towerHeight; i++) {
        for (int j = 0; j < towerHeight - i; j++) {
            int color = tower[i - 1][j] ^ tower[i - 1][j + 1];
            tower[i][j] = color;
            robotCount[color]--;
            if (robotCount[color] < 0) {
                // printTower();
                // cout << color << endl;
                return false;
            }
        }
    }
    // cout << "t" << endl;
    return true;
}

int search(int pos = 0) {
    // cout << pos << endl;
    if (pos >= towerHeight) {
        return isAvailableTower();
    }

    int count = 0;
    for (int i = 0; i <= 1; i++) {
        tower[0][pos] = i;
        robotCount[i]--;
        if (robotCount[i] >= 0) {
            count += search(pos + 1);
        }
        robotCount[i]++;
    }
    return count;
}

int main() {
    while (cin >> robotCount[0] >> robotCount[1]) {
        calcTowerHeight();
        cout << search() << endl;
    }
}
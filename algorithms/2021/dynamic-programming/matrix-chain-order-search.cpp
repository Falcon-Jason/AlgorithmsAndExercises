/**
 * # 矩阵链乘法问题
 * 
 * ## 问题描述
 * - 见 _C.L.R.S_ P211
 * 
 * ## 实现
 * - 记忆化搜索
 * 
 */

#include <iostream>

using namespace std;

constexpr int SIZE = 1024;

int matrix_widths[SIZE];
int min_costs[SIZE][SIZE];

inline int width(int i) { return matrix_widths[i]; }
inline int height(int i) { return matrix_widths[i + 1]; }

int calc_cost(int i, int k, int j) {
    return width(i) * height(k) * height(j);
}

int search(int i, int j) {
    if (j == i) {
        return 0;
    } else if (min_costs[i][j] != 0) {
        return min_costs[i][j];
    } else if (j == i + 1) {
        min_costs[i][j] = width(i) * width(j) * height(j);
    } else {
        int min_cost = INT_MAX;
        for (int k = i; k < j; k++) {
            int cost = search(i, k) + search(k + 1, j) + calc_cost(i, k, j);
            min_cost = min(min_cost, cost);
        }
        min_costs[i][j] = min_cost;
    }
    return min_costs[i][j];
}

void print_min_costs(int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            cout << min_costs[i][j] << "\t";
        }
        cout << endl;
    }
}

void read_matrix(int length) {
    for (int i = 0; i < length + 1; i++) {
        cin >> matrix_widths[i];
    }
}

int main() {
    int length;
    cin >> length;
    read_matrix(length);

    cout << search(0, length - 1) << endl;

    print_min_costs(length);
}
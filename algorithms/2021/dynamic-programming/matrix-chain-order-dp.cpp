/**
 * # 矩阵链乘法问题
 * 
 * ## 问题描述
 * - 见 _C.L.R.S_ P211
 * 
 * ## 实现
 * - 动态规划（简单区间DP）
 * 
 */

#include <iostream>

using namespace std;

constexpr int SIZE = 1024;

int matrix_widths[SIZE];
int min_costs[SIZE][SIZE];

inline int width(int i) { return matrix_widths[i]; }
inline int height(int i) { return matrix_widths[i + 1]; }

inline int calc_cost(int i, int k, int j) {
    return width(i) * height(k) * height(j);
}

int min_cost_iter(int i, int j) {
    int min_cost = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = min_costs[i][k] + min_costs[k + 1][j] + calc_cost(i, k, j);
        min_cost = min(min_cost, cost);
    }
    return min_cost;
}

int min_cost(int chain_length) {
    for (int i = 0; i < chain_length; i++) {
        min_costs[i][i] = 0;
        min_costs[i][i + 1] = width(i) * width(i + 1) * width(i + 2);
    }

    for (int step = 2; step < chain_length; step++) {
        for (int i = 0; i < chain_length - step; i++) {
            int j = i + step;
            min_costs[i][j] = min_cost_iter(i, j);
        }
    }
    return min_costs[0][chain_length - 1];
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

    cout << min_cost(length) << endl;

    print_min_costs(length);
}
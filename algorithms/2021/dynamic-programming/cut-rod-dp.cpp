/** 
 * # 钢条切割问题
 * 
 * ## 问题描述 
 * - 见 _C.L.R.S_ P.204
 * - 基于公式 (15.1)
 * 
 * ## 实现
 * - 动态规划（简单背包DP）
 */

#include <iostream>
#include <algorithm>

using namespace std;

constexpr int SIZE = 1024;

int prices[SIZE];
int max_prices[SIZE];

int cut_rod_iter(int index) {
    max_prices[index] = prices[index];
    for (int i = 1; i <= index / 2; i++) {
        max_prices[index] = max(
            max_prices[index],
            max_prices[i] + max_prices[index - i]);
    }
    return max_prices[index];
}

int cut_rod(int rod_length) {
    max_prices[0] = 0;
    max_prices[1] = prices[1];
    for (int i = 2; i <= rod_length; i++) {
        cut_rod_iter(i);
    }
    return max_prices[rod_length];
}

int main() {
    int rod_length;
    cin >> rod_length;
    for (int i = 1; i <= rod_length; i++) {
        cin >> prices[i];
    }
    cut_rod(rod_length);
    for (int i = 1; i <= rod_length; i++) {
        cout << max_prices[i] << " ";
    }
    cout << endl;
}
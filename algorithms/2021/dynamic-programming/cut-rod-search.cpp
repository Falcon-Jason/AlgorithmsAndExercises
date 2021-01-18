/** 
 * # 钢条切割问题
 * 
 * ## 问题描述 
 * - 见 _C.L.R.S_ P.204
 * - 基于公式 (15.1)
 * 
 * ## 实现
 * - 记忆化搜索
 */

#include <algorithm>
#include <iostream>

using namespace std;

constexpr int SIZE = 1024;

int prices[SIZE];
int max_prices[SIZE];

int cut_rod(int length) {
    if (length == 0) {
        return 0;
    }
    if (max_prices[length] != 0) {
        return max_prices[length];
    }

    max_prices[length] = prices[length];
    for (int i = 1; i <= length / 2; i++) {
        max_prices[length] = max(
            max_prices[length],
            cut_rod(i) + cut_rod(length - i));
    }
    return max_prices[length];
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
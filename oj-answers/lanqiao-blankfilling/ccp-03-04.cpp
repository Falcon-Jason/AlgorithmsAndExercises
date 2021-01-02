#include <deque>
#include <iostream>
using namespace std;

const char* pokers[] = {
    "A", "2", "3", "4", "5",
    "6", "7", "8", "9", "10",
    "J", "Q", "K"};

deque<int> hand;  // 手中的牌，front为牌堆顶，back为牌堆底

int main() {
    hand.push_back(12);
    for (int i = 11; i >= 0; --i) {
        hand.push_back(i);
        hand.push_back(hand.front());
        hand.pop_front();
    }

    // 最下面的那张牌输出为第一个数据，故从牌堆底(end)向牌堆顶(front)迭代输出
    cout << pokers[hand.back()];
    for (auto i = next(hand.rbegin()); i != hand.rend(); i++) {
        cout << "," << pokers[*i];
    }
    cout << endl;
}
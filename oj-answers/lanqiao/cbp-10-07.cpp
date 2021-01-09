#include <iostream>
#include <algorithm>
using namespace std;

long long layer_sum[20];
int layer_count;

void set_layer_count(int length) {
    for (int i = 0; i <= 20; i++) {
        if ((1 << i) > length) {
            layer_count = i;
            return;
        }
    }
}

void read_sums(int length) {
    for (int i = 0; i < layer_count; i++) {
        layer_sum[i] = 0;
        int cur_layer = min(1 << i, length);
        for (int j = 0; j < cur_layer; j++) {
            int val;
            cin >> val;
            layer_sum[i] += val;
        }

        length -= cur_layer;
    }
}

int max_layer() {
    int max = 0;
    for (int i = 1; i < layer_count; i++) {
        if (layer_sum[i] > layer_sum[max]) {
            max = i;
        }
    }
    return max + 1;
}

int main() {
    int length;
    cin >> length;
    set_layer_count(length);
    read_sums(length);
    cout << max_layer() << endl;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>

typedef long long ll;

int char_to_int(char ch) {
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    } else if (ch >= 'a' && ch <= 'z') {
        return ch - 'a' + 10;
    } else if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 10;
    }
    return 0;
}

ll string_to_int(const char* str, int radix) {
    ll result = 0;
    while (isalnum(*str)) {
        result *= radix;
        result += char_to_int(*str);
        str++;
    }
    return result;
}

int min_radix(const char* s) {
    int max_digit = 2;
    while (isalnum(*s)) {
        int digit = char_to_int(*s);
        max_digit = std::max(max_digit, digit);
        s++;
    }
    return max_digit + 1;
}

int find_equal_radix(const char* s, const char* t, int radixS) {
    ll valS = string_to_int(s, radixS);
    for (int i = min_radix(t); i <= 36; i++) {
        if (valS == string_to_int(t, i)) {
            return i;
        }
    }
    return -1;
}

int main() {
    constexpr int SIZE = 16;
    char n1[SIZE];
    char n2[SIZE];
    int tag;
    int radix;

    scanf("%16s%16s%d%d", n1, n2, &tag, &radix);
    int result = find_equal_radix(tag == 1 ? n1 : n2, tag == 1 ? n2 : n1, radix);
    if (result == -1) {
        printf("Impossible\n");
    } else {
        printf("%d\n", result);
    }
}

// WA
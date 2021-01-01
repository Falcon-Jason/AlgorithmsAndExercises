#include <iostream>

int main()
{
    int x;
    std::cin >> x;

    int b, s, n;
    b = x / 100;
    s = x % 100 / 10;
    n = x % 10;

    for (int i = 0; i < b;i++)
        std::cout << "B";
    for (int i = 0; i < s;i++)
        std::cout << "S";
    if(n == 0)
        return 0;
    for (int i = 1; i <= n;i++)
        std::cout << i;
        return 0;
}
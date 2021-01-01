#include <iostream>
#include <cstdint>

using namespace std;
int main()
{
    int t;
    cin >> t;
    int64_t a, b, c;
    for (int i = 0; i < t;i++){
        cin >> a >> b >> c;
        cout << ("Case #") << (i + 1) << (": ") << (a + b > c ? "true" : "false") << endl;
    }
    return 0;
}

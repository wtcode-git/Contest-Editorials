#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int ans = (y - x + 9) / 10;
    if (ans < 0)
        ans = 0;
    cout << ans << "\n";
    return 0;
}
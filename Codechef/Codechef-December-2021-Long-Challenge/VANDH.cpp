#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
}

string operator*(string str, unsigned int n) {
    string ans = "";
    while (n) {
        if (n & 1)
            ans += str;
        str += str;
        n /= 2;
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    if (n == m) {
        cout << 2 * (n + 1) << endl;
        cout << (string) "10" * (n + 1) << endl;
    } else {
        cout << 2 * (min(m, n) + 1) + 1 + 3 * (abs(m - n) - 1) << endl;
        if (n < m) {
            cout << (string) "10" * (min(m, n) + 1) << "1"
                 << (string) "101" * (abs(m - n) - 1) << endl;
        } else {
            cout << (string) "01" * (min(m, n) + 1) << "0"
                 << (string) "010" * (abs(m - n) - 1) << endl;
        }
    }
}

int main() {
    fastIO();
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
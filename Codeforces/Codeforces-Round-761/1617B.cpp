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

void solve() {
    int n;
    cin >> n;
    int c = 1;
    n--;
    int a, b;
    if (n & 1)
        a = n / 2;
    else {
        if (n % 4 == 0)
            a = n / 2 - 1;
        else
            a = n / 2 - 2;
    }
    b = n - a;
    cout << a << " " << b << " " << c << endl;
}

int main() {
    fastIO();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
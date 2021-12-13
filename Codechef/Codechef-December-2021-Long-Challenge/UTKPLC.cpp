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
    vector<char> priority(3);
    for (int i = 0; i < 3; i++)
        cin >> priority[i];
    vector<char> offers(2);
    for (int i = 0; i < 2; i++)
        cin >> offers[i];
    char ans = '\0';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            if (priority[i] == offers[j]) {
                ans = priority[i];
                goto ext;
            }
        }
    }
ext:
    cout << ans << endl;
}

int main() {
    fastIO();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
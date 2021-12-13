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
    map<int, int> frq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        frq[x]++;
    }
    if (frq.size() == 1)
        cout << 0 << endl;
    else {
        int max_frq = 0;
        for (pair<int, int> ff : frq)
            max_frq = max(max_frq, ff.second);
        if (n == 1 || max_frq == n)
            cout << 0 << endl;
        else if (max_frq == 1)
            cout << -1 << endl;
        else
            cout << n - max_frq + 1 << endl;
    }
}

int main() {
    fastIO();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
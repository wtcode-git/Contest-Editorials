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

inline bool isPowOf2(long long n) { return (n & (n - 1)) == 0; }

void reduce(long long &n) {
    if (isPowOf2(n)) {
        n = 0;
        return;
    }
    int b = 0;
    while ((1LL << b) < n)
        b++;
    n = (1LL << b) - n;
}

void solve() {
    int n;
    cin >> n;
    vector<int> data(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    long long a = data[0], b = data[1];
    vector<long long> redn[2];
    redn[0].clear();
    redn[1].clear();
    while (a != 0) {
        redn[0].push_back(a);
        reduce(a);
    }
    while (b != 0) {
        redn[1].push_back(b);
        reduce(b);
    }
    while (!(redn[0].empty() || redn[1].empty()) && (redn[0].back() == redn[1].back())) {
        redn[0].pop_back();
        redn[1].pop_back();
    }
    cout << 1 << " " << 2 << " " << redn[0].size() + redn[1].size() << endl;
}

int main() {
    fastIO();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
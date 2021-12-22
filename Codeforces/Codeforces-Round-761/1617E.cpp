#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/detail/standard_policies.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define pbds tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long

void fastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
}

inline bool isPowOf2(long long n) { return (n & (n - 1)) == 0; }

int reduce(int chocolate) {
    if (isPowOf2(chocolate))
        return 0;
    for (int i = 0;; i++)
        if ((1 << i) >= chocolate)
            return (1 << i) - chocolate;
}

class christmas_tree {
private:
    unordered_map<int, pair<int, unordered_set<int>>> edges;

public:
    int i1, i2;
    int ans;
    christmas_tree() { i1 = i2 = ans = 0, edges.clear(); }
    void nodeIndx(int node, int indx) { edges[node].first = indx; }
    void add_edge(int u, int v) {
        edges[u].first = 0;
        edges[v].first = 0;
        edges[u].second.insert(v);
    }
    pair<int, int> diameter(int node) {
        int d1 = 0, d2 = 0;
        int _i1 = 0, _i2 = 0;
        for (int child : edges[node].second) {
            pair<int, int> tmp = diameter(child);
            if (tmp.first > d1)
                d2 = d1, _i2 = _i1, d1 = tmp.first, _i1 = tmp.second;
            else if (tmp.first > d2)
                d2 = tmp.first, _i2 = tmp.second;
        }
        if (_i1 == 0 && edges[node].first)
            _i1 = edges[node].first;
        else if (_i2 == 0 && edges[node].first)
            _i2 = edges[node].first;
        int dm = d1 + d2 + 1;
        if (_i1 && _i2 && dm > ans)
            i1 = _i1, i2 = _i2, ans = dm;
        return make_pair(d1 + 1, _i1);
    }
};

void solve() {
    int n;
    cin >> n;
    christmas_tree data;
    vector<int> chocolates(0);
    for (int i = 0; i < n; i++) {
        int chocolate;
        cin >> chocolate;
        chocolates.push_back(chocolate);
        while (chocolate != 0) {
            int chocolate_r = reduce(chocolate);
            data.add_edge(chocolate_r, chocolate);
            chocolate = chocolate_r;
        }
    }
    for (int i = 0; i < n; i++)
        data.nodeIndx(chocolates[i], i + 1);
    data.diameter(0);
    cout << data.i1 << " " << data.i2 << " " << data.ans - 1 << endl;
}

int main() {
    fastIO();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
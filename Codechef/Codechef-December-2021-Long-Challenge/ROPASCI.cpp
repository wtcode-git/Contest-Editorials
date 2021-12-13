#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ff first
#define ss second

void fastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
}

map<pair<char, char>, bool> battle;
void init() {
    battle[mp('P', 'P')] = false;
    battle[mp('P', 'R')] = true;
    battle[mp('P', 'S')] = false;
    battle[mp('R', 'P')] = false;
    battle[mp('R', 'R')] = false;
    battle[mp('R', 'S')] = true;
    battle[mp('S', 'P')] = true;
    battle[mp('S', 'R')] = false;
    battle[mp('S', 'S')] = false;
}

vector<pair<char, pair<int, int>>> reduce(string str) {
    int n = str.length();
    vector<pair<char, pair<int, int>>> reduced(0);
    reduced.push_back(mp(str[0], mp(0, 0)));
    for (int i = 1; i < n; i++) {
        if (reduced.back().ff == str[i])
            reduced.rbegin()->second.ss++;
        else
            reduced.push_back(mp(str[i], mp(i, i)));
    }
    reduced.push_back(mp('\0', mp(n, n)));
    return reduced;
}

void solve() {
    int n;
    string str;
    cin >> n >> str;
    vector<pair<char, pair<int, int>>> reduced = reduce(str);
    int s = reduced.size() - 2;
    string ans(n, '0');
    while (s >= 0) {
        if (reduced[s + 1].ff == '\0') {
            for (int i = reduced[s].ss.ff; i <= reduced[s].ss.ss; i++)
                ans[i] = reduced[s].ff;
            goto ext;
        }
        if (battle[mp(reduced[s].ff, reduced[s + 1].ff)]) {
            if (reduced[s + 2].ff == '\0') {
                for (int i = reduced[s].ss.ff; i <= reduced[s].ss.ss; i++)
                    ans[i] = reduced[s].ff;
                goto ext;
            }
            for (int i = reduced[s].ss.ff; i <= reduced[s].ss.ss; i++)
                ans[i] = ans[reduced[s + 2].ss.ff];
            goto ext;
        } else {
            for (int i = reduced[s].ss.ff; i <= reduced[s].ss.ss; i++)
                ans[i] = ans[reduced[s + 1].ss.ff];
            goto ext;
        }
    ext:
        s--;
    }
    cout << ans << endl;
}

int main() {
    fastIO();
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
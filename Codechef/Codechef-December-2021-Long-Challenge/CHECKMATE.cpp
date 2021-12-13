#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define inRange(l, m, r) (l < r && l <= m && m <= r)
#define cpr(x) cin >> x.ff >> x.ss
#define ret return

void fastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
}

inline bool slf(pair<int, int> king, pair<int, int> r1, pair<int, int> r2, bool a, bool b, bool c, int l, int f) {
    if (r1.ff == l && a && (b || r2.ff == f))
        ret 1;
    if (r2.ff == l && b && (a || r1.ff == f))
        ret 1;
    if (r1.ff == f && a) {
        if (r2.ff == l && (inRange(1, r2.ss, king.ss - 1) || inRange(king.ss + 1, r2.ss, 8)))
            ret 1;
        if (b && c)
            ret 1;
    }
    if (r2.ff == f && b) {
        if (r1.ff == l && (inRange(1, r1.ss, king.ss - 1) || inRange(king.ss + 1, r1.ss, 8)))
            ret 1;
        if (a && c)
            ret 1;
    }
    ret 0;
}

inline bool sls(pair<int, int> king, pair<int, int> r1, pair<int, int> r2, bool a, bool b, bool c, int l, int f) {
    if (r1.ss == l && a && (b || r2.ss == f))
        ret 1;
    if (r2.ss == l && b && (a || r1.ss == f))
        ret 1;
    if (r1.ss == f && a) {
        if (r2.ss == l && (inRange(1, r2.ff, king.ff - 1) || inRange(king.ff + 1, r2.ff, 8)))
            ret 1;
        if (b && c)
            ret 1;
    }
    if (r2.ss == f && b) {
        if (r1.ss == l && (inRange(1, r1.ff, king.ff - 1) || inRange(king.ff + 1, r1.ff, 8)))
            ret 1;
        if (a && c)
            ret 1;
    }
    ret 0;
}

void solve() {
    pair<int, int> king, r1, r2;
    cpr(king);
    cpr(r1);
    cpr(r2);
    if (inRange(2, king.ff, 7) && inRange(2, king.ss, 7)) {
        cout << "no\n";
        ret;
    }
    bool aa = abs(king.ff - r1.ff) > 1;
    bool ab = abs(king.ss - r1.ss) > 1;
    bool ba = abs(king.ff - r2.ff) > 1;
    bool bb = abs(king.ss - r2.ss) > 1;
    bool ca = r1.ff != r2.ff;
    bool cb = r1.ss != r2.ss;
    if (king.ff == 1 && slf(king, r1, r2, ab, bb, cb, 1, 2))
        goto yes;
    if (king.ff == 8 && slf(king, r1, r2, ab, bb, cb, 8, 7))
        goto yes;
    if (king.ss == 1 && sls(king, r1, r2, aa, ba, ca, 1, 2))
        goto yes;
    if (king.ss == 8 && sls(king, r1, r2, aa, ba, ca, 8, 7))
        goto yes;
    cout << "no\n";
    ret;
yes:
    cout << "yes\n";
    ret;
}

int main() {
    fastIO();
    int t;
    cin >> t;
    while (t--)
        solve();
    ret 0;
}
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mod 1000000007
#define NN 100000

void fastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
}

map<ll, int> trigdata;

vector<int> fact(NN);
vector<int> ifact(NN);

int mul(int x, int y) {
    return (int)((x * 1LL * y) % mod);
}
int mod_inv(int x) {
    ll b = x;
    ll res = 1;
    int p = mod - 2;
    while (p) {
        if (p & 1)
            res = (res * b) % mod;
        b = (b * b) % mod;
        p /= 2;
    }
    return res;
}

void build_facts() {
    fact[0] = 1;
    for (int i = 1; i < NN; i++)
        fact[i] = mul(i, fact[i - 1]);
    ifact[NN - 1] = mod_inv(fact[NN - 1]);
    for (int i = NN - 2; i > -1; i--)
        ifact[i] = mul(i + 1, ifact[i + 1]);
}

int ncr(unsigned int n, unsigned int r) {
    return mul(mul(ifact[r], ifact[n - r]), fact[n]);
}

void solve() {
    ll s, e;
    cin >> s >> e;
    if (e < s) {
        cout << 0 << endl;
        return;
    }
    auto b1 = prev(trigdata.lower_bound(s));
    auto b2 = prev(trigdata.lower_bound(e));
    int n = b2->ss - b1->ss;
    ll dx = e - s - b2->ff + b1->ff;
    if (dx < 0 || dx > n) {
        cout << 0 << endl;
        return;
    }
    cout << ncr(n, dx) << endl;
}

int main() {
    fastIO();
    trigdata.clear();
    for (int i = -1; i < NN; i++)
        trigdata[((i + 1) * 1LL * (i + 2)) / 2] = i;
    build_facts();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
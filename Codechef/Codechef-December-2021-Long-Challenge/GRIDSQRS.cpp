#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second

void fastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
}

void solve() {
    int n;
    cin >> n;
    vector<string> a(n, string(n, '0'));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<vector<int>> row(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        row[i][0] = a[i][0] - '0';
        for (int j = 1; j < n; j++) {
            int x = a[i][j] - '0';
            row[i][j] = x ? (row[i][j - 1] + 1) : 0;
        }
    }

    vector<vector<int>> col(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        col[0][i] = a[0][i] - '0';
        for (int j = 1; j < n; j++) {
            int x = a[j][i] - '0';
            col[j][i] = x ? (col[j - 1][i] + 1) : 0;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '0')
                continue;
            int lim = min(i, j) + 1;
            for (int k = 0; k < lim; k++) {
                int lr = i - k, cr = j - k;
                int x = row[i][j], y = row[lr][j], z = col[i][j], m = col[i][cr];
                if (x > k && y > k && z > k && m > k)
                    ans++;
            }
        }
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
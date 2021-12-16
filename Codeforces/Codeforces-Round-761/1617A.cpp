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

void next_permutation(string &str) {
    int n = str.size();
    if (n < 2)
        return;
    int p = n - 1;
    for (int i = p - 1; i >= 0; i--) {
        if (str[i] < str[p]) {
            swap(str[i], str[p]);
            sort(str.begin() + i, str.begin() + p);
            return;
        }
    }
    return;
}

void solve() {
    string s, t;
    vector<int> s_data(26, 0);
    map<char, int> t_data;
    cin >> s >> t;
    for (char c : s)
        s_data[c - 'a']++;
    if (!s_data[0] || !s_data[1] || !s_data[2]) {
        sort(s.begin(), s.end());
        cout << s << endl;
        return;
    }
    for (char c : t)
        t_data[c]++;
    string tmp = "";
    for (auto tt : t_data)
        tmp += string(tt.second, tt.first);
    if (tmp == t)
        next_permutation(tmp);
    string ans = "";
    ans += string(s_data[tmp[0] - 'a'], tmp[0]);
    ans += string(s_data[tmp[1] - 'a'], tmp[1]);
    ans += string(s_data[tmp[2] - 'a'], tmp[2]);
    // cout << ans << endl;
    for (int i = 3; i < 26; i++)
        ans += string(s_data[i], 'a' + i);
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
/*
    author:ujwalll
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define nx cout << "\n";
const int INF = 1 << 29;
const int MOD = 1e9 + 7;
#define pp pair<ll, ll>
#define ppi pair<int, int>
typedef long long int ll;
#define pri(x) printf("%d ", x);
#define prl(x) printf("%lld ", x);
#define fi first;
#define se second;
#define pb push_back;
#define all(v) v.begin(), v.end()
#define minimum 1
#define maximum 1e5 
#define random minimum + (rand() % static_cast<int>(maximum - minimum + 1))

bool isPowerOfTwo(ll x){
    return x && (!(x & (x - 1)));
}
void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
long long binpow(long long a, long long b){
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll ncr(int n, int r) {
    if (n < 0 || r < 0 || r > n)
        return 0;

    ll ans = 1;
    for (int i = 1; i <= r; i++) {
        ans *= (n + 1 - i);
        ans /= i;
    }

    return ans;
}
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};
////////////////////////////////////////////////////////////////////


void test_case(){
    int n;
    cin>>n;
    string a[n - 2];
    rep(i, n - 2) cin >> a[i];
    string ans = "";
    bool f = 0;
    rep(i, n - 2){
        if(i + 1 < n - 2 && a[i+1][0] != a[i][1]){
            f = 1;
            ans+=a[i][0];
            ans+=a[i][1];
        }
        else ans+=a[i][0];
    }
    ans+=a[n - 3][1];
    if(!f) ans += 'a';
    cout << ans;
    nx;
}
int main(){
    fastio();
    int tc = 1;
    cin>>tc;
    while(tc--){
        test_case();
        done:;
    }
    return 0;
}
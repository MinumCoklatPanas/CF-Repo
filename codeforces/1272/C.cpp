#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MOD = 1e9 + 7;
const ll MAXN = 1e3;
const double EPS = 1e-9;

map<char,ll> bisa;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (ll i = 1 ; i <= k ; i++) {
        char ta;
        cin >> ta;
        bisa[ta] = 1;
    }
    ll ans = 0;
    ll cnt = 0;
    for (ll i = 0 ; i < n ; i++) {
        if (!bisa[s[i]]) {
            // cout << i << endl;
            ans += (cnt * (cnt + 1)) / 2;
            cnt = 0;
        }
        else {
            ++cnt;
        }
        
    }
    ans += (cnt * (cnt + 1)) / 2;
    cout << ans << endl;
}
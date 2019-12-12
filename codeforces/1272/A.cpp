#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MOD = 1e9 + 7;
const ll MAXN = 1e3;
const double EPS = 1e-9;

ll cnt(vector< ll > tab,ll ix) {
    if (ix == 3) {
        ll ret = 0;
        ret += abs(tab[0] - tab[1]);
        ret += abs(tab[0] - tab[2]);
        ret += abs(tab[1] - tab[2]);
        return ret;
    }
    ll tmp = tab[ix];
    ll ans = INFF;
    tab[ix] = tmp - 1;
    ans = min(ans,cnt(tab,ix + 1));
    tab[ix] = tmp;
    ans = min(ans,cnt(tab,ix + 1));
    tab[ix] = tmp + 1;
    ans = min(ans,cnt(tab,ix + 1));
    return ans;
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll q;
    cin >> q;
    while (q--) {
        vector<ll> tab(3);
        cin >> tab[0] >> tab[1] >> tab[2];
        ll ans = cnt(tab,0);
        cout << ans << endl;
    }
}
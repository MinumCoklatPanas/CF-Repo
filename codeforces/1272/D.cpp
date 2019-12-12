#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MOD = 1e9 + 7;
const ll MAXN = 1e3;
const double EPS = 1e-9;

ll tab[200010];
ll LIS[200010];
ll maxKiri[200010];
ll LDS[200010];
ll maxKanan[200010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    for (ll i = 1 ; i <= n ; i++)
        cin >> tab[i];
    LIS[1] = 1;
    for (ll i = 1 ; i <= n ; i++) {
        if (tab[i - 1] < tab[i])
            LIS[i] = LIS[i - 1] + 1;
        else
            LIS[i] = 1;
        maxKiri[i] = max(LIS[i],maxKiri[i - 1]);
    }

    LDS[n] = 1;
    for (ll i = n ; i >= 1 ; i--) {
        if (tab[i + 1] > tab[i])
            LDS[i] = LDS[i + 1] + 1;
        else
            LDS[i] = 1;
        maxKanan[i] = max(LDS[i],maxKanan[i + 1]);
    }
    // cout << LIS[2] << " " << LDS[4] << endl;
    ll ans = maxKiri[n];
    for (ll i = 1 ; i <= n ; i++) {
        ans = max(ans,maxKiri[i - 1]);
        ans = max(ans,maxKanan[i + 1]);
        if (tab[i - 1] < tab[i + 1])
            ans = max(ans,LIS[i - 1] + LDS[i + 1]);
    }
    cout << ans << endl;
}
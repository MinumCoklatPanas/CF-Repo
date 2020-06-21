#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

ll frek[100010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll sum = 0;
    for (ll i = 1 ; i <= n ; i++)
    {
        ll ta;
        cin >> ta;
        frek[ta]++;
        sum += ta;
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll b,c;
        cin >> b >> c;
        ll hilang = frek[b] * b;
        ll muncul = frek[b] * c;
        ll delta = muncul - hilang;
        sum += delta;
        cout << sum << endl;
        frek[c] += frek[b];
        frek[b] = 0;
    }
    return 0;
}

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

ll need[3];
ll have[3];
ll price[3];
ll k;

bool can(ll num)
{
    ll cost = 0;
    if (need[0] > 0)
        cost += max(0ll,(need[0] * num - have[0])) * price[0];
    // cout << cost << " cost\n";
    if (need[1] > 0)
        cost += max(0ll,(need[1] * num - have[1])) * price[1];
    // cout << cost << endl;
    if (need[2] > 0)
        cost += max(0ll,(need[2] * num - have[2])) * price[2];
    // cout << cost << endl;
    // cout << cost << endl;
    return (cost <= k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    for (ll i = 0 ; i < s.length() ; i++)
    {
        if (s[i] == 'S')
            need[0]++;
        if (s[i] == 'B')
            need[1]++;
        if (s[i] == 'C')
            need[2]++;
    }
    cin >> have[1] >> have[0] >> have[2];
    cin >> price[1] >> price[0] >> price[2];
    cin >> k;
    // can(1);
    // return 0;
    ll ans = INFF;
    ll l = 0;
    ll r = (ll)1e14;
    while (r - l > 1)
    {
        ll mid = (l + r) >> 1ll;
        if (can(mid))
            l = mid;
        else
            r = mid - 1;
    }
    if (can(r))
        cout << r << endl;
    else
        cout << l << endl;
    return 0;
}
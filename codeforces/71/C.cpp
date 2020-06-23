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

bool tab[100010];

ll cei(ll x,ll y)
{
    return ((x / y));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    for (ll i = 0 ; i < n ; i++)
        cin >> tab[i];
    ll maxLen = n;
    // cout << maxLen << endl;
    for (ll len = maxLen ; len >= 1 ; len--) if (n % len == 0)
    {
        if (n / len < 3) continue;
        bitset< 100010 > bs;
        for (ll i = 0 ; i < len ; i++)
            bs[i] = tab[i];
        for (ll i = 1 ; i * len < n ; i++)
        {
            for (ll j = 0 ; j < len && i * len + j < n ; j++)
                bs[j] = bs[j] & tab[i * len + j];
            // cout << bs << endl;
        }
        if (bs.any())
        {
            // cout << len << endl;
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
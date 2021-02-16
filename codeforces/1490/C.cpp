#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

set<ll> cubes;

void solve()
{
    ll n;
    cin >> n;
    for (ll i = 1 ; i * i * i <= n ; i++)
    {
        ll rem = n - (i * i * i);
        if (cubes.find(rem) != cubes.end())
        {
            // cout << rem << endl;
            cout << "YES\n";
            // exit(0);
            return;
        }
    }
    cout << "NO\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (ll i = 1 ; i <= 10000 ; i++)
        cubes.insert(i * i * i);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
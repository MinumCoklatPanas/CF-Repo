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

void solve()
{
    string s;
    cin >> s;
    bool ada = 0;
    for (int i = 0 ; i < s.length() ; i++) ada |= ((s[i] - '0') % 2 == 0);
    if (!ada)
        cout << -1 << endl;
    else
    {
        const auto get = [&](char c) -> int
        {
            return c - '0';
        };
        if (get(s.back()) % 2 == 0)
            cout << 0 << endl;
        else
        if (get(s[0]) % 2 == 0)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
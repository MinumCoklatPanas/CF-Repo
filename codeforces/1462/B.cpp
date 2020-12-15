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
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s.substr(0,4) == "2020")
    {
        cout << "YES\n";
        return;
    }
    reverse(s.begin(),s.end());
    if (s.substr(0,4) == "0202")
    {
        cout << "YES\n";
        return;
    }
    reverse(s.begin(),s.end());
    string t = s;
    reverse(t.begin(),t.end());
    if (s[0] == '2' && t.substr(0,3) == "020")
    {
        cout << "YES\n";
        return;
    }
    if (s[0] == '2' && s[1] == '0' && t.substr(0,2) == "02")
    {
        cout << "YES\n";
        return;
    }
    if (s[0] == '2' && s[1] == '0' && s[2] == '2' && t[0] == '0')
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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
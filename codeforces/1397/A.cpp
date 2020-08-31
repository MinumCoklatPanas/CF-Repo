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

int frek[30];

void solve()
{
    memset(frek,0,sizeof(frek));
    int n;
    cin >> n;
    // cout << n << endl;
    for (int i = 1 ; i <= n ; i++)
    {
        string s;
        cin >> s;
        for (int j = 0 ; j < s.length() ; j++)
            frek[s[j] - 'a']++;
    }
    // cout << "yo"
    for (int i = 0 ; i < 26 ; i++)
    {
        if (frek[i] % n != 0)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
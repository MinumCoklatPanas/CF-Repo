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

int pref[500010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    pref[0] = (s[0] == '|');
    for (int i = 1 ; i < s.length() ; i++)
    {
        pref[i] = pref[i - 1];
        pref[i] += (s[i] == '|');
    }
    int l = -1;
    bool ada = 0;
    for (int i = 0 ; i < s.length() ; i++)
    {
        if (s[i] == '[')
            ada = 1;
        else
        if (s[i] == ':' && ada)
        {
            l = i;
            break;
        }
    }
    if (l == -1)
    {
        cout << "-1\n";
        return 0;
    }
    ada = 0;
    int r = -1;
    for (int i = s.length() - 1 ; i > l ; i--)
    {
        if (s[i] == ']')
            ada = 1;
        else
        if (s[i] == ':' && ada)
        {
            r = i;
            break;
        }
    }
    if (r == -1)
    {
        cout << "-1\n";
        return 0;
    }
    int ans = 4 + pref[r] - pref[l - 1];
    cout << ans << endl;
    return 0;
}
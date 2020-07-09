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

int tab[100010];
map<char,int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int k;
    cin >> k;
    for (int i = 1 ; i <= k ; i++)
    {
        char a,b;
        cin >> a >> b;
        mp[a] = 2 * i - 1;
        mp[b] = 2 * i;
    }
    int n = s.length();
    for (int i = 0 ; i < n ; i++)
        tab[i + 1] = mp[s[i]];
    int i = 1;
    int ans = 0;
    while (i <= n)
    {
        int cur = tab[i];
        int cntA = 0;
        int cntB = 0;
        while (i <= n)
        {
            int tmp = (tab[i] + 1) / 2;
            if (tmp != (cur + 1) / 2) break;
            if (tab[i] % 2 == 1)
                ++cntA;
            else
                ++cntB;
            ++i;
        }
        ans += min(cntA,cntB);
    }
    cout << ans << endl;
    return 0;
}
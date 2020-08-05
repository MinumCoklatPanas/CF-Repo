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

int frek[110];

void solve()
{
    int n;
    cin >> n;
    memset(frek,0,sizeof(frek));
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        frek[ta]++;
    }
    int ans = 0;
    for (int i = 2 ; i <= 100 ; i++)
    {
        int cnt = 0;
        for (int j = 1 ; 2 * j <= i ; j++)
        {
            if (2 * j == i)
                cnt += frek[j] / 2;
            else
                cnt += min(frek[j],frek[i - j]);
        }
        ans = max(ans,cnt);
    }
    cout << ans << endl;
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
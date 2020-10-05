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
#define int long long

int cnt[70];
int ans[100010];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll u,v;
    cin >> u >> v;
    if (u > v)
    {
        cout << "-1\n";
        return 0;
    }
    if ((u % 2) != (v % 2))
    {
        cout << "-1\n";
        return 0;
    }
    int curSum = 0;
    for (int i = 61 ; i >= 0 ; i--)
    {
        cnt[i] = ((u & (1ll << i)) > 0);
        curSum += cnt[i] * (1ll << i);
    }
    for (int i = 61 ; i >= 0 ; i--)
    {
        for (int j = cnt[i] + 2 ; ; j += 2)
        {
            if (curSum + (1ll << (i + 1)) <= v)
            {
                cnt[i] = j;
                curSum += (1ll << (i + 1));
            }
            else
                break;
        }
    }
    int mx = *max_element(cnt,cnt + 62);
    cout << mx << endl;
    for (int i = 0 ; i <= 60 ; i++)
    {
        for (int j = 1 ; j <= cnt[i] ; j++)
            ans[j] |= (1ll << i);
    }
    for (int i = 1 ; i <= mx ; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
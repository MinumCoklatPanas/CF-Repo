#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct point
{
    int x,y;
};

int cnt[1000010];
point tab[255];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) cnt[i] = 1;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> tab[i].x >> tab[i].y;
    }
    for (int i = 1 ; i <= m ; i++)
    {
        for (int j = 1 ; j <= m ; j++) if (j != i)
        {
            // cout << i << " " << j << endl;
            int dy = tab[i].y - tab[j].y;
            int dx = tab[i].x - tab[j].x;
            if (dy == 0) continue;
            if ((tab[i].y * dx) % dy == 0)
            {
                int ret = 2;
                for (int k = 1 ; k <= m ; k++) if (i != k && j != k)
                    ret += ((dy * (tab[i].x - tab[k].x)) == (dx * (tab[i].y - tab[k].y)));
                int x = tab[i].x - (tab[i].y * dx / dy);
                if (1 <= x && x <= n) cnt[x] = max(cnt[x],ret);
            }
        }
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) ans += cnt[i];
    cout << ans << endl;
    return 0;
}
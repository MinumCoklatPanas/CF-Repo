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
#define MULTI_TC 0

int getTC()
{
    if (MULTI_TC)
    {
        int t;
        cin >> t;
        return t;
    }
    else return 1;
}

char tab[1010][1010];
int cnt[1010][1010];
string cur[1010][1010];
int lst[1010][1010];

void solve()
{
    int n,m;
    cin >> n >> m;
    // cerr << n << " " << m << endl;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= m ; j++)
            cin >> tab[i][j];

    const auto f = [&](int x) -> int
    {
        return (x * (x + 1)) / 2;
    };
    int ans = 0;
    for (int i = 1 ; i <= m ; i++)
    {
        vector<pair<char,int>> v;
        v.emplace_back(tab[1][i],1);
        for (int j = 2 ; j <= n ; j++)
        {
            if (tab[j][i] == v.back().first)
                ++v.back().second;
            else
                v.emplace_back(tab[j][i],1);
        }
        // for (auto it : v)
        //     cerr << it.first << "," << it.second << " ";
        // cerr << endl;
        int sum = v[0].second;
        for (int j = 1 ; j + 1 < v.size() ; j++)
        {
            if (v[j].second <= min(v[j - 1].second,v[j + 1].second))
            {
                int len = v[j].second;
                int l = sum - len + 1;
                // assert(l >= 1);
                int r = sum + 2 * len;
                // assert(r <= n);
                string tmp = "";
                tmp += v[j - 1].first;
                tmp += v[j].first;
                tmp += v[j + 1].first;
                // cerr << l << " " << r << endl;
                if (tmp != cur[l][r] || lst[l][r] != i - 1)
                {
                    // cerr << l << " " << r << " masuk\n";
                    ans += f(cnt[l][r]);
                    cur[l][r] = tmp;
                    cnt[l][r] = 1;
                }
                else
                {
                    ++cnt[l][r];
                    // cerr << l << " " << r << " " << cnt[l][r] << endl;
                    // cerr << l << " " << r << " masuk\n";
                }
                lst[l][r] = i;
                // cerr << l << " " << r << endl;
            }
            sum += v[j].second;
        }
    }
    // cerr << cnt[2][4] <
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= n ; j++) if (cnt[i][j])
        {
            // cout << cnt[i][j] << endl;
            ans += f(cnt[i][j]);
        }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = getTC();
    while (t--)
    {
        solve();
    }
    return 0;
}
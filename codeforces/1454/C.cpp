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
    vector< vector<int> > pos(n + 5);
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        pos[ta].push_back(i);
    }
    int ans = INF;
    for (int i = 1 ; i <= n ; i++) if (pos[i].size() > 0)
    {
        int cnt = 0;
        for (int j = 0 ; j < pos[i].size() ; j++)
        {
            if (j == 0 && pos[i][j] != 1) ++cnt;
            if (j == pos[i].size() - 1 && pos[i][j] != n) ++cnt;
            if (j + 1 < pos[i].size())
            {
                if (pos[i][j + 1] != pos[i][j] + 1) ++cnt;
            }
        }
        ans = min(ans,cnt);
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
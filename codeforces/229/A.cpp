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

vector<int> pos[110];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            char ta;
            cin >> ta;
            if (ta == '1')
                pos[i].push_back(j);
        }
        int sz = pos[i].size();
        if (sz == 0)
        {
            cout << -1 << endl;
            return 0;
        }
        for (int j = 0 ; j < sz ; j++)
            pos[i].push_back(pos[i][j] + m);
    }
    int ans = INF;
    for (int col = 1 ; col <= m ; col++)
    {
        int ret = 0;
        for (int i = 1 ; i <= n ; i++)
        {
            int ixKanan = lower_bound(pos[i].begin(),pos[i].end(),col) - pos[i].begin();
            int kanan = pos[i][ixKanan];
            int distKanan = abs(kanan - col);
            int ixKiri = upper_bound(pos[i].begin(),pos[i].end(),col + m) - pos[i].begin() - 1;
            int kiri = pos[i][ixKiri];
            int distKiri = abs(kiri - (col + m));
            ret += min(distKanan,distKiri);
        }
        ans = min(ans,ret);
    }
    cout << ans << endl;
    return 0;
}
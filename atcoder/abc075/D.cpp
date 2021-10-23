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

int tab[55][55];

int f(int x1,int y1,int x2,int y2)
{
    int ret = tab[x2][y2];
    ret -= tab[x1 - 1][y2];
    ret -= tab[x2][y1 - 1];
    ret += tab[x1 - 1][y1 - 1];
    return ret;
}

void solve()
{
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> points(n);
    vector<int> x,y;
    map<int,int> mpX,mpY;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> points[i].first >> points[i].second;
        x.push_back(points[i].first);
        y.push_back(points[i].second);
    }
    const auto compress = [&](vector<int> &v) -> void
    {
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
    };
    compress(x);
    compress(y);
    for (int i = 0 ; i < x.size() ; i++)
        mpX[x[i]] = i + 1;
    for (int i = 0 ; i < y.size() ; i++)
        mpY[y[i]] = i + 1;
    for (auto &it : points)
    {
        it.first = mpX[it.first];
        it.second = mpY[it.second];
        tab[it.first][it.second]++;
    }
    for (int i = 1 ; i <= x.size() ; i++)
    {
        for (int j = 1 ; j <= y.size() ; j++)
        {
            tab[i][j] += tab[i - 1][j];
            tab[i][j] += tab[i][j - 1];
            tab[i][j] -= tab[i - 1][j - 1];
            // cerr << tab[i][j] << " ";
        }
        // cerr << endl;
    }
    // cerr << f(1,1,4,4) << endl;
    int ans = LLONG_MAX;
    for (int x1 = 1 ; x1 <= x.size() ; x1++)
        for (int x2 = x1 ; x2 <= x.size() ; x2++)
            for (int y1 = 1 ; y1 <= y.size() ; y1++)
                for (int y2 = y1 ; y2 <= y.size() ; y2++)
                {
                    int cnt = f(x1,y1,x2,y2);
                    if (cnt >= k)
                    {
                        int area = abs(x[x1 - 1] - x[x2 - 1]) * abs(y[y1 - 1] - y[y2 - 1]);
                        ans = min(area,ans);
                    }
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
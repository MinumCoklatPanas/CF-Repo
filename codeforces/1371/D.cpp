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
#define MULTI_TC 1

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

void solve()
{
    int n,k;
    cin >> n >> k;
    deque<int> dq;
    for (int i = 0 ; i < n ; i++) dq.push_back(i);
    vector< vector<int> > ans(n,vector<int>(n,0));
    for (int i = 0 ; i < k ; i++)
    {
        if (i % n == 0)
        {
            int tmp = dq.back();
            dq.pop_back();
            dq.push_front(tmp);
        }
        int r = i % n;
        int c = dq[i % n];
        // cout << r << " " << c << " [";
        // for (auto it : dq)
        //     cout << it << ",";
        // cout << "]\n";
        ans[r][c] = 1;
    }
    int maxR = -INF;
    int minR = INF;
    for (auto it : ans)
    {
        int cnt = 0;
        for (auto it2 : it)
        {
            cnt += it2;
        }
        maxR = max(maxR,cnt);
        minR = min(minR,cnt);
    }
    int maxC = -INF;
    int minC = INF;
    for (int i = 0 ; i < n ; i++)
    {
        int cnt = 0;
        for (int j = 0 ; j < n ; j++)
        {
            cnt += ans[j][i];
        }
        maxC = max(maxC,cnt);
        minC = min(minC,cnt);
    }
    int diffR = (maxR - minR);
    int diffC = (maxC - minC);
    int ret = (diffR * diffR) + (diffC * diffC);
    cout << ret << endl;
    for (auto it : ans)
    {
        for (auto it2 : it)
            cout << it2;
        cout << endl;
    }
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
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

set<int> pos[100010];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        pos[ta].insert(i);
    }
    int curNum = 1;
    int curPos = 1;
    int cnt = 0;
    int curTot = n;
    int ans = 0;
    while (1)
    {
        while (pos[curNum].size() == 0 && curNum <= 100000) ++curNum;
        if (curNum > 100000) break;
        auto it = pos[curNum].lower_bound(curPos);
        if (it == pos[curNum].end())
        {
            ans += curTot;
            curTot -= cnt;
            cnt = 0;
            curPos = 1;
        }
        else
        {
            curPos = *it;
            pos[curNum].erase(it);
            ++cnt;
        }
    }
    ans += cnt;
    cout << ans << endl;
    return 0;
}
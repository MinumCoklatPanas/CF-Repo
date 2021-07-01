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

void solve()
{
    vector< pair<int,int> > point(3);
    vector<int> xVals,yVals;
    for (auto &it : point)
    {
        cin >> it.first >> it.second;
        xVals.push_back(it.first);
        yVals.push_back(it.second);
    }
    sort(xVals.begin(),xVals.end());
    sort(yVals.begin(),yVals.end());
    pair<int,int> mid = {xVals[1],yVals[1]};
    set< pair<int,int> > ans;

    const auto makePath = [&](int ix) -> void
    {
        auto tmp = mid;
        ans.insert(tmp);
        while (tmp.first < point[ix].first)
        {
            ans.insert(tmp);
            ++tmp.first;
        }
        ans.insert(tmp);
        while (tmp.first > point[ix].first)
        {
            ans.insert(tmp);
            --tmp.first;
        }
        ans.insert(tmp);

        while (tmp.second < point[ix].second)
        {
            ans.insert(tmp);
            ++tmp.second;
        }
        ans.insert(tmp);
        while (tmp.second > point[ix].second)
        {
            ans.insert(tmp);
            --tmp.second;
        }
        ans.insert(tmp);
    };

    makePath(0);
    makePath(1);
    makePath(2);
    
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it.first << " " << it.second << endl;
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
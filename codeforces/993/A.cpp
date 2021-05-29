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
    vector< pair<int,int> > a1(4),a2(4),b1(4),b2(4);
    for (int i = 0 ; i < 4 ; i++)
    {
        cin >> a1[i].first >> a1[i].second;
        a2[i].first = a1[i].first + a1[i].second;
        a2[i].second = a1[i].first - a1[i].second;
    }
    for (int i = 0 ; i < 4 ; i++)
    {
        cin >> b1[i].first >> b1[i].second;
        b2[i].first = b1[i].first + b1[i].second;
        b2[i].second = b1[i].first - b1[i].second;
    }
    const auto cek = [&](vector<pair<int,int>> a,vector<pair<int,int>> b) -> bool
    {
        int minX = INF,minY = INF,maxX = -INF,maxY = -INF;
        for (auto it : a)
        {
            minX = min(minX,it.first);
            minY = min(minY,it.second);
            maxX = max(maxX,it.first);
            maxY = max(maxY,it.second);
        }
        for (auto it : b)
        {
            if ((minX <= it.first && it.first <= maxX) && (minY <= it.second && it.second <= maxY))
                return 1;
        }
        return 0;
    };
    const auto cekCenter = [&](vector<pair<int,int>> a,vector<pair<int,int>> b) -> bool
    {
        int minX = INF,minY = INF,maxX = -INF,maxY = -INF;
        for (auto it : b)
        {
            minX = min(minX,it.first);
            minY = min(minY,it.second);
            maxX = max(maxX,it.first);
            maxY = max(maxY,it.second);
        }
        pair<double,double> center = {(maxX + minX) * 0.5,(maxY + minY) * 0.5};
        // cout << center.first << " " << center.second << endl;
        minX = INF,minY = INF,maxX = -INF,maxY = -INF;
        for (auto it : a)
        {
            minX = min(minX,it.first);
            minY = min(minY,it.second);
            maxX = max(maxX,it.first);
            maxY = max(maxY,it.second);
        }
        return ((minX <= center.first && center.first <= maxX) && (minY <= center.second && center.second <= maxY));
    };

    // cout << cekCenter(a1,b1) << endl;
    // return;
    
    if (cek(a1,b1) || cek(b2,a2) || cekCenter(a1,b1) || cekCenter(b2,a2))
    {
        cout << "YES\n";
    }
    else
        cout << "NO\n";
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
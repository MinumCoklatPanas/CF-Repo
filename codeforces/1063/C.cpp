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
    int n;
    cin >> n;
    vector< deque<pair<int,int>> > tab(2);
    
    const auto query = [](int x,int y) -> int
    {
        cout << x << " " << y << endl;
        string s;
        cin >> s;
        return (s == "white");
    };

    int l = query(1,1);
    int r = l ^ 1;
    tab[l].emplace_back(1,1);
    int lo = 1;
    int hi = INF;
    for (int i = 1 ; i < n ; i++)
    {
        int mid = (lo + hi) >> 1;
        int col = query(mid,1);
        if (col == l)
        {
            tab[l].emplace_back(mid,1);
            lo = mid;
        }
        else
        {
            tab[r].emplace_front(mid,1);
            hi = mid;
        }
    }
    if (tab[l].size() == 0 || tab[r].size() == 0)
    {
        cout << "0 0 0 2\n";
        return;
    }
    cout << tab[l].back().first << " " << 0 << " " << tab[r].front().first << " " << 2 << endl;
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
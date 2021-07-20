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
    int n;
    cin >> n;
    const auto ask = [](int l,int r) -> int
    {
        cout << 1 << " " << r - l + 1 << " ";
        cout << 1 << " ";
        for (int i = l ; i <= r ; i++)
        {
            if (i == r)
                cout << i << endl;
            else
                cout << i << " ";
        }
        int ret;
        cin >> ret;
        return ret;
    };
    int maxDist = ask(2,n);
    int l = 2;
    int r = n;
    while (l < r)
    {
        // cout << l << " " << r << endl;
        int mid = (l + r) >> 1;
        int tmp = ask(l,mid);
        if (tmp == maxDist)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    int deepest = l;
    vector<int> asked;
    for (int i = 1 ; i <= n ; i++) if (i != deepest) asked.push_back(i);
    cout << 1 << " " << n - 1 << " " << deepest << " ";
    for (int i = 0 ; i < n - 1 ; i++)
    {
        if (i == 0)
            cout << asked[i];
        else
            cout << " " << asked[i];
    }
    cout << endl;
    int maxDist2;
    cin >> maxDist2;
    cout << -1 << " " << maxDist2 << endl;
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
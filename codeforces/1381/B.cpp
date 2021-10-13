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
    n *= 2;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    tab.push_back(INF);
    vector<int> nums;
    int curMax = 0;
    int cnt = 0;
    for (int i = 0 ; i < n ; i++)
    {
        if (tab[i] > curMax)
        {
            nums.push_back(cnt);
            curMax = tab[i];
            cnt = 1;
        }
        else
            ++cnt;
    }
    bitset<2010> bs;
    bs[0] = 1;
    for (auto it : nums)
    {
        bs |= (bs << it);
    }
    if (bs[n / 2])
        cout << "YES\n";
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
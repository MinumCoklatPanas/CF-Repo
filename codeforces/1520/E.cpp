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

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pos;
    int sum = 0;
    for (int i = 0 ; i < n ; i++) if (s[i] == '*')
    {
        pos.push_back(i + 1);
        sum += i + 1;
    }
    if (pos.size() == 0)
    {
        cout << "0\n";
        return;
    }
    vector<int> pref(pos.size(),0);
    pref[0] = pos[0];
    for (int i = 1 ; i < pos.size() ; i++)
        pref[i] = pref[i - 1] + pos[i];
    const auto getSum = [&](int l,int r) -> int
    {
        int ret = ((r - l + 1) * (l + r)) / 2;
        return ret;
    };
    int cnt = pos.size();
    int ans = INFF;
    for (int i = pos[0] ; i <= n ; i++)
    {
        int closest = upper_bound(pos.begin(),pos.end(),i) - pos.begin() - 1;
        int cntKiri = closest + 1;
        int sumKiri = getSum(i - cntKiri + 1,i);
        int costKiri = sumKiri - pref[closest];
        int cntKanan = cnt - cntKiri;
        int sumKanan = getSum(i + 1,(i + 1) + (cntKanan - 1));
        int costKanan = (sum - pref[closest]) - sumKanan;
        ans = min(ans,costKanan + costKiri);
        // break;
    }
    cout << ans << endl;
}

signed main()
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
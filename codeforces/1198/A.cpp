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
    int n,k;
    cin >> n >> k;
    k *= 8;
    vector<int> nums;
    map<int,int> frek;
    for (int i = 0 ; i < n ; i++)
    {
        int ta;
        cin >> ta;
        frek[ta]++;
        nums.push_back(ta);
    }
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    vector<int> pref;
    pref.push_back(frek[nums[0]]);
    // cerr << pref.back() << " ";
    for (int i = 1 ; i < nums.size() ; i++)
    {
        pref.push_back(pref.back() + frek[nums[i]]);
        // cerr << pref.back() << " ";
    }
    // cerr << endl;

    const auto get = [&](int l,int r) -> int
    {
        return (l == 0 ? pref[r] : pref[r] - pref[l - 1]);
    };

    int ans = INF;
    for (int i = 0 ; (1 << i) <= nums.size() * 2 ; i++)
    {
        int len = min((1ll << i),(int)nums.size());
        if (n * i > k) break;
        for (int j = 0 ; j + len - 1 < nums.size() ; j++)
        {
            int l = j;
            int r = j + len - 1;
            int sum = get(l,r);
            int ubah = n - sum;
            // cerr << l << " " << r << " " << sum << endl;
            ans = min(ans,ubah);
        }
        // break;
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
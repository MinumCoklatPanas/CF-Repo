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

struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unordered_map<int,int,custom_hash> mp[11];
    int n,k;
    cin >> n >> k;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;

    const auto countDigit = [&](int x) -> int
    {
        if (x == 0) return 1;
        int ret = floor(log10(x) + 1.0);
        return ret;
    };

    int ans = 0;

    for (auto it : tab)
    {
        int mod = it % k;
        int need = (k - mod) % k;
        int cnt = countDigit(it);
        ans += mp[cnt][need];
        int pengali = 10;
        for (int i = 1 ; i < 11 ; i++)
        {
            int tot = (it * pengali) % k;
            mp[i][tot]++;
            pengali *= 10;
            pengali %= k;
        }
    }

    for (int i = 1 ; i < 11 ; i++) mp[i].clear();
    reverse(tab.begin(),tab.end());

    for (auto it : tab)
    {
        int mod = it % k;
        int need = (k - mod) % k;
        int cnt = countDigit(it);
        ans += mp[cnt][need];
        int pengali = 10;
        for (int i = 1 ; i < 11 ; i++)
        {
            int tot = (it * pengali) % k;
            mp[i][tot]++;
            pengali *= 10;
            pengali %= k;
        }
    }

    cout << ans << endl;
}
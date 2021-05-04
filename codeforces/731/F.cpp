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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> tab(n);
    vector<int> frek(200010,0);
    vector<int> pref(200010,0);
    for (auto &it : tab)
    {
        cin >> it;
        frek[it] += 1;
    }
    for (int i = 1 ; i <= 200000 ; i++)
        pref[i] = pref[i - 1] + frek[i];

    const auto get = [&](int l,int r) -> int
    {
        return pref[r] - pref[l - 1];
    };
    
    int ans = 0;
    for (int i = 1 ; i <= 200000 ; i++) if (frek[i])
    {
        int it = i;
        int sum = 0;
        for (int j = it ; j <= 200000 ; j += it)
        {
            sum += get(j,min(j + it - 1,200000ll)) * j;
        }
        ans = max(ans,sum);
    }
    cout << ans << endl;
    return 0;
}
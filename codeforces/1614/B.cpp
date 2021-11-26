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
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    vector<pair<int,int>> sorted;
    for (int i = 0 ; i < n ; i++)
        sorted.push_back({tab[i],i});
    sort(sorted.begin(),sorted.end());
    reverse(sorted.begin(),sorted.end());
    vector<int> ans(n);
    int l = -1,r = 1;
    int sum = 0;
    for (int i = 0 ; i < n ; i++)
    {
        int jarakL = abs(l);
        int jarakR = abs(r);
        int nambahL = 2 * jarakL * sorted[i].first;
        int nambahR = 2 * jarakR * sorted[i].first;
        if (nambahL < nambahR)
        {   
            sum += nambahL;
            ans[sorted[i].second] = l;
            --l;
        }
        else
        {
            ans[sorted[i].second] = r;
            sum += nambahR;
            ++r;
        }
    }
    cout << sum << endl;
    cout << 0 << " ";
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
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
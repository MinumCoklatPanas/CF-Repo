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
    vector<string> tab(n);
    for (auto &it : tab) cin >> it;
    int ans = 0;
    for (char i = 'a' ; i <= 'e' ; i++)
    {
        vector<int> tmp;
        for (auto it : tab)
        {
            int cnt = 0;
            for (auto it2 : it)
            {
                if (it2 == i)
                    ++cnt;
                else
                    --cnt;
            }
            tmp.push_back(cnt);
        }
        sort(tmp.begin(),tmp.end());
        reverse(tmp.begin(),tmp.end());
        int hitung = 0;
        int sum = 0;
        for (int j = 0 ; j < n ; j++)
        {
            sum += tmp[j];
            if (sum <= 0) break;
            hitung++;
        }
        ans = max(ans,hitung);
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
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
    string s;
    cin >> s;
    const auto prefix_function = [&](string str) -> vector<int>
    {
        int n = str.length();
        vector<int> ret(n,0);
        for (int i = 1 ; i < n ; i++)
        {
            int j = ret[i - 1];
            while (j > 0 && str[i] != str[j])
            {
                j = ret[j - 1];
            }
            if (str[i] == str[j]) ++j;
            ret[i] = j;
        }
        return ret;
    };
    vector<int> pi = prefix_function(s);
    int n = s.length();
    int tmp = pi[n - 1];
    // cout << tmp << endl;
    vector<int> ans;
    while (tmp > 0)
    {
        ans.push_back(tmp);
        tmp = pi[tmp - 1];
    }
    vector<int> frek(n + 1,0);
    for (int i = 0 ; i < n ; i++) frek[pi[i]]++;
    for (int i = n - 1 ; i > 0 ; i--) frek[pi[i - 1]] += frek[i];
    for (int i = 0 ; i <= n ; i++) frek[i]++;
    reverse(ans.begin(),ans.end());
    cout << ans.size() + 1 << endl;
    for (auto it : ans)
    {
        cout << it << " " << frek[it] << endl;
    }
    cout << n << " " << 1 << endl;
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
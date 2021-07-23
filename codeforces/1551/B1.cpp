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
    string s;
    cin >> s;

    int n = s.length(),k = 2;
    // cin >> n >> k;
    vector< vector<int> > pos(26);
    vector<int> tab(n);
    for (int i = 0 ; i < n ; i++)
    {
        tab[i] = s[i] - 'a';
        pos[tab[i]].push_back(i);
    }
    vector<int> ans(n,0);
    vector<int> sisa;
    for (int i = 0 ; i < 26 ; i++)
    {
        if (pos[i].size() >= k)
        {
            for (int j = 0 ; j < k ; j++)
                ans[pos[i][j]] = j + 1;
        }
        else
        {
            for (auto it : pos[i]) sisa.push_back(it);
        }
    }
    int cnt = 0;
    // cerr << sisa.size() << endl;
    // return;
    for (int i = 0 ; i + k <= sisa.size() ; i += k)
    {
        for (int j = i ; j < i + k ; j++)
            ans[sisa[j]] = j - i + 1;
    }
    for (auto it : ans) 
    {
        cnt += (it != 0);
        // cerr << it << " ";
    }
    // cerr << endl;
    assert(cnt % 2 == 0);
    cout << cnt / 2 << endl;
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
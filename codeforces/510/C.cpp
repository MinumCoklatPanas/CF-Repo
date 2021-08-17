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
    int n;
    cin >> n;
    vector<string> tab(n);
    for (auto &it : tab) cin >> it;
    vector<bool> dah(n,0);
    vector<vector<int>> adj(26);
    vector<int> inDeg(26,0);
    const auto get = [&](char c) -> int
    {
        return c - 'a';
    };
    for (int pos = 0 ; pos < 100 ; pos++)
    {
        for (int i = 0 ; i + 1 < n ; i++) if (!dah[i] && tab[i].length() > pos)
        {
            if (tab[i + 1].length() <= pos)
            {
                cout << "Impossible\n";
                return;
            }
            if (tab[i][pos] != tab[i + 1][pos])
            {
                inDeg[get(tab[i + 1][pos])]++;
                adj[get(tab[i][pos])].push_back(get(tab[i + 1][pos]));
                dah[i] = 1;
            }
        }
    }
    queue<int> q;
    for (int i = 0 ; i < 26 ; i++) if (inDeg[i] == 0)
        q.push(i);
    string ans = "";
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        ans += 'a' + cur;
        for (auto it : adj[cur])
        {
            --inDeg[it];
            if (inDeg[it] == 0)
                q.push(it);
        }
    }
    if (ans.size() != 26)
        cout << "Impossible\n";
    else
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
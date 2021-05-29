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
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    for (int i = 0 ; i < n ; i++)
    {
        if (tab[i] > i + 1)
        {
            cout << -1 << endl;
            return;
        }
    }
    vector<int> ans(n);
    set<int> avail;
    int start = 0;
    while (start < n && tab[start] == 0) 
    {
        avail.insert(start);
        ++start;
    }
    if (start == n)
    {
        for (int i = 0 ; i < n ; i++)
            cout << 1 << " ";
        cout << endl;
        return;
    }
    ans[start] = 0;
    int curMex = 1;
    while (curMex < tab[start])
    {
        int ubah = *avail.rbegin();
        ans[ubah] = curMex;
        ++curMex;
        avail.erase(avail.find(ubah));
    }
    ++start;
    for (int i = start ; i < n ; i++)
    {
        avail.insert(i);
        if (tab[i] > tab[i - 1])
        {
            while (curMex < tab[i])
            {
                int ubah = *avail.rbegin();
                ans[ubah] = curMex;
                ++curMex;
                avail.erase(avail.find(ubah));
            }   
        }
    }
    for (auto it : avail)
        ans[it] = 1000000;
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
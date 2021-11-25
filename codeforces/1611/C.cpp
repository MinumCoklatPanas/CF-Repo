#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
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
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    deque<int> ans;
    if (tab[0] != n && tab[n - 1] != n)
        cout << -1 << endl;
    else
    {
        int l = 0,r = n - 1;
        if (tab[0] == n) l++;
        if (tab[n - 1] == n) --r;
        ans.push_back(n);
        for (int i = 1 ; i < n ; i++)
        {
            if (tab[l] < tab[r])
            {
                ans.push_front(tab[l]);
                ++l;
            }
            else
            {
                ans.push_back(tab[r]);
                --r;
            }
        }
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
}

int main()
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
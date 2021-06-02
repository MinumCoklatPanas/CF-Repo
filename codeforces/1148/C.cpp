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
    vector<int> tab(n + 1);
    vector<int> pos(n + 1,0);
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        pos[tab[i]] = i;
    }
    if (n == 2)
    {
        if (tab[1] < tab[2])
            cout << 0 << endl;
        else
        {
            cout << 1 << endl;
            cout << 1 << " " << 2 << endl;
        }
        return;
    }
    vector< pair<int,int> > ans;

    const auto Swap = [&](int x,int y) -> void
    {
        ans.push_back({x,y});
        int xx = tab[x];
        int yy = tab[y];
        swap(tab[x],tab[y]);
        swap(pos[xx],pos[yy]);
    };
    //fix 1
    if (pos[1] != (n / 2) + 1)
    {
        if (pos[1] > n / 2)
        {
            Swap(1,pos[1]);
        }
        else
        {
            Swap(pos[1],n);
            Swap(n,1);
        }
        Swap(1,(n / 2) + 1);
    }
    if (pos[n] != (n / 2))
    {
        if (pos[n] > n / 2)
        {
            Swap(pos[n],1);
            Swap(1,n);
        }
        else
        {
            Swap(pos[n],n);
        }
        Swap(n,n / 2);
    }
    for (int i = 2 ; i < n / 2 ; i++)
    {
        if (pos[i] < n / 2)
        {
            Swap(pos[i],n);
        }
        else
        {
            Swap(pos[i],1);
            Swap(1,n);
        }
        Swap(n,i);
    }
    for (int i = (n / 2) + 2 ; i < n ; i++)
    {
        if (pos[i] > n / 2)
        {
            Swap(pos[i],1);
        }
        else
        {
            Swap(pos[i],n);
            Swap(n,1);
        }
        Swap(1,i);
    }
    if (tab[n] != n / 2)
        Swap(1,n);
    Swap(1,(n / 2) + 1);
    Swap(n,n / 2);
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it.first << " " << it.second << endl;
    assert(ans.size() <= 5 * n);
    assert(is_sorted(tab.begin(),tab.end()));
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
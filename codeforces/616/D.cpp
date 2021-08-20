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
    int n,k;
    cin >> n >> k;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    vector<int> frek(1000005,0);
    int cnt = 0;
    const auto add = [&](int x) -> void
    {
        if (x == -1) 
        {
            cerr << "yo\n";
            return;
        }
        frek[x]++;
        if (frek[x] == 1)
            cnt++;
        // cerr << "add " << x << " " << cnt << endl;
    };
    const auto rem = [&](int x) -> void
    {
        frek[x]--;
        if (frek[x] == 0)
            cnt--;
    };

    const auto cek = [&](int x) -> bool
    {
        for (int i = 0 ; i <= 1000000 ; i++) frek[i] = 0;
        cnt = 0;
        for (int i = 0 ; i < x ; i++) add(tab[i]);
        // cerr << cnt << endl;
        if (cnt <= k) return true;
        for (int i = x ; i < n ; i++)
        {
            rem(tab[i - x]);
            add(tab[i]);
            // cerr << cnt << endl;
            if (cnt <= k) return true;
        }
        return false;
    };
    // cek(5);
    // return;

    int l = 1;
    int r = n;
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        if (cek(mid))
            l = mid;
        else
            r = mid - 1;
    }
    const auto print = [&](int x) -> void
    {
        for (int i = 0 ; i <= 1000000 ; i++) frek[i] = 0;
        cnt = 0;
        for (int i = 0 ; i < x ; i++) add(tab[i]);
        if (cnt <= k)
        {
            cout << 1 << " " << x << endl;
            return;
        }
        for (int i = x ; i < n ; i++)
        {
            rem(tab[i - x]);
            add(tab[i]);
            if (cnt <= k)
            {
                cout << i - x + 2 << " " << i + 1 << endl;
                return;
            }   
        }
    };

    if (cek(r))
    {
        print(r);
    }
    else
    {
        print(l);
    }
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
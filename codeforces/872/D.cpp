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
    vector<int> a(n),b(n); //(i,0) (0,i)
    const auto ask = [&](int x,int y) -> int
    {
        int ret;
        cout << "? " << x << " " << y << endl;
        cin >> ret;
        return ret;
    };
    for (int i = 0 ; i < n ; i++)
    {
        a[i] = ask(i,0);
        b[i] = ask(0,i);
    }
    // cout << "yo\n";
    // return;
    vector<vector<int>> ans;
    for (int i = 0 ; i < n ; i++)
    {
        vector<int> p(n);
        vector<int> ada(n,0);
        bool fail = 0;
        for (int j = 0 ; j < n ; j++)
        {
            p[j] = a[j] ^ i;
            if (p[j] >= n)
            {
                fail = 1;
                break;
            } 
            // cerr << p[j] << endl;
            if (ada[p[j]]) fail = 1;
            ada[p[j]] = 1;
        }
        // continue;
        if (fail) continue;
        vector<int> pos(n);
        for (int j = 0 ; j < n ; j++)
            pos[p[j]] = j;
        vector<int> aa(n),bb(n);
        for (int j = 0 ; j < n ; j++)
        {
            aa[j] = p[j] ^ pos[0];
            bb[j] = p[0] ^ pos[j];
        }
        if (aa == a && bb == b)
            ans.push_back(p);
        // return;
    }
    if (ans.size() == 0)
        cout << -1 << endl;
    else
    {
        cout << "!" << endl;
        cout << ans.size() << endl;
        for (auto it : ans[0])
            cout << it << " ";
        cout << endl;
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
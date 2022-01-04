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
    vector<int> nxt(n + 5,-1);
    const auto ask = [&](int x) -> int
    {
        cout << "? " <<  x << endl;
        int ret;
        cin >> ret;
        if (!ret)
        {
            exit(0);
        }
        return ret;
    };
    // int tmp = ask(1);
    int cnt = 0;
    for (int i = 1 ; i <= n ; i++) if (nxt[i] == -1)
    {
        int awal = ask(i);   
        int cur = awal;
        do
        {
            nxt[cur] = ask(i);
            cur = nxt[cur];
        } while (cur != awal);
    }
    cout << "! ";
    for (int i = 1 ; i <= n ; i++)
    {
        assert(nxt[i] != -1);
        cout << nxt[i] << " ";
    }
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
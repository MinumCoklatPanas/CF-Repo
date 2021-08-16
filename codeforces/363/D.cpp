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
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto &it : a) cin >> it;
    sort(a.begin(),a.end());
    vector<int> b(m);
    for (auto &it : b) cin >> it;
    sort(b.begin(),b.end());
    const auto cek = [&](int x) -> bool
    {
        int tmp = k;
        int ptr = 0;
        for (int i = n - x ; i < n ; i++)
        {
            if (b[ptr] > a[i])
                tmp -= b[ptr] - a[i];
            ++ptr;
        }   
        return (tmp >= 0);
    };
    // cek(4);
    // return;
    int l = 0;
    int r = min(n,m);
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        if (cek(mid))
            l = mid;
        else
            r = mid - 1;
    }
    const auto process = [&](int x) -> void
    {
        int tmp = k;
        int ptr = 0;
        int spent = 0;
        for (int i = n - x ; i < n ; i++)
        {
            if (b[ptr] > a[i])
            {
                tmp -= b[ptr] - a[i];
                spent += a[i];
            }
            else
                spent += b[ptr];
            ++ptr;
        }   
        spent -= tmp;
        spent = max(spent,0ll);
        cout << x << " " << spent << endl;
    };
    if (cek(r))
        process(r);
    else
        process(l);
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
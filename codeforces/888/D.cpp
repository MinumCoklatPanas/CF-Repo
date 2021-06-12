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
    int ans = 1;

    const auto perm = [&](int x) -> int
    {
        vector<int> tmp;
        for (int i = 1 ; i <= x ; i++) tmp.push_back(i);
        int ret = 0;
        do
        {
            bool valid = 1;
            for (int i = 0 ; i < x ; i++)
            {
                if (tmp[i] == i + 1)
                {
                    valid = 0;
                    break;
                }
            }
            if (valid) ++ret;
        } while (next_permutation(tmp.begin(),tmp.end()));
        return ret;  
    };

    for (int i = 2 ; i <= k ; i++)
    {
        int tmp = perm(i);
        int atas = 1;
        for (int j = n ; j > n - i ; j--)
            atas *= j;
        int bawah = 1;
        for (int j = 1 ; j <= i ; j++)
            bawah *= j;
        // cerr << i << " " << atas << " " << bawah << endl;
        tmp *= atas / bawah;
        ans += tmp;
    }
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
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

int ceil(int x,int y)
{
    return (x / y) + (x % y != 0);
}

void solve()
{
//     for (int i = 2 ; i <= 100 ; i++)
//     {
//         int mn = INF;
//         int opt = -1;
//         for (int j = 0 ; j <= i ; j++)
//         {
//             int tmp = j + ceil(i,j + 1);
//             if (tmp < mn)
//             {
//                 mn = tmp;
//                 opt = j;
//             }
//         }
//         cout << i << " " << opt << " " << mn << endl;
//     }
    // return;
    int n,d;
    cin >> n >> d;
    if (d <= n)
        cout << "YES\n";
    else
    {
        for (int j = 0 ; j * j <= d ; j++)
        {
            int tmp = j + ceil(d,j + 1);
            if (tmp <= n)
            {
                // cerr << j << " " << tmp << endl;
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
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
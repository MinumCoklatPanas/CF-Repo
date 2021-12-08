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

bool isPrime[100010];
int dp[110];

void solve()
{
    // for (int i = 1 ; i <= 100 ; i++) dp[i] = -1;
    // for (int i = 6 ; i <= 100 ; i++)
    // {
    //     for (int j = isPrime[i] ; j < )
    // }
    int n;
    cin >> n;
    if (n < 6)
    {
        if (n != 4)
            cout << -1 << endl;
        else
            cout << 1 << endl;
    }
    else
    {
        if (n % 4 == 0)
            cout << n / 4 << endl;
        else
        if (n % 4 == 1)
        {
            if (n < 9)
                cout << -1 << endl;
            else
            {
                int res = n - 9;
                cout << (res / 4) + 1 << endl;
            }
        }
        else
        if (n % 4 == 2)
        {
            if (n < 6)
                cout << -1 << endl;
            else
            {
                int res = n - 6;
                cout << (res / 4) + 1  << endl;
            }
        }
        else
        if (n % 4 == 3)
        {
            if (n < 15)
                cout << -1 << endl;
            else
            {
                int res = n - 15;
                cout << (res / 4) + 2 << endl;
            }
        }
    }

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1] = 0;
    isPrime[0] = 0;
    for (int i = 2 ; i <= 100000 ; i++) if (isPrime[i])
    {
        for (int j = i + 1 ; j <= 100000 ; j += i)
            isPrime[j] = 0;
    }
    int t = getTC();
    while (t--)
    {
        solve();
    }
    return 0;
}
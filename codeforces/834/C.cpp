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
        scanf("%lld",&t);
        // cin >> t;
        return t;
    }
    else return 1;
}

bool isPrime[100010];
vector<int> primes;

void solve()
{
    int a,b;
    // cin >> a >> b;
    scanf("%lld %lld",&a,&b);
    int l = 1;
    int r = 1000000;
    int akar = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int cb = mid * mid * mid;
        if (cb == a * b)
        {
            akar = mid;
            break;
        }
        else
        if (cb > a * b)
            r = mid - 1;
        else
            l = mid + 1;
    }
    if (akar == -1)
        cout << "No\n";
    else
    {
        if ((a % akar == 0) && (b % akar == 0))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

signed main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1] = 0;
    for (int i = 2 ; i <= 100000 ; i++) if (isPrime[i])
    {
        primes.push_back(i);
        for (int j = i * i ; j <= 100000 ; j += i)
            isPrime[j] = 0;
    }
    int t = getTC();
    while (t--)
    {
        solve();
    }
    return 0;
}
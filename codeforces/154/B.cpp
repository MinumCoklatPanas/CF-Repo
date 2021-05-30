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
    int n,m;
    cin >> n >> m;
    vector<int> rep(n + 1,-1);
    vector<bool> isPrime(100000 + 1,1);
    vector<bool> ada(n + 1,0);
    vector<int> primes;
    isPrime[1] = 0;
    for (int i = 2 ; i <= 100000 ; i++) if (isPrime[i])
    {
        primes.push_back(i);
        for (int j = i + i ; j <= 100000 ; j += i) 
            isPrime[j] = 0;
    }
    for (int j = 1 ; j <= m ; j++)
    {
        char op;
        int ta;
        cin >> op >> ta;
        if (op == '+')
        {
            if (ada[ta])
            {
                cout << "Already on\n";
                continue;
            }
            int tmp = ta;
            vector<int> factors;
            for (int i = 0 ; primes[i] * primes[i] <= tmp ; i++) if (tmp % primes[i] == 0)
            {
                factors.push_back(primes[i]);
                while (tmp % primes[i] == 0)
                    tmp /= primes[i];
            }
            if (tmp >= 2) factors.push_back(tmp);
            bool can = 1;
            int ans = -1;
            for (auto it : factors)
            {
                if (rep[it] != -1)
                {
                    can = 0;
                    ans = rep[it];
                    break;
                }
            }
            if (can)
            {
                for (auto it : factors) rep[it] = ta;
                ada[ta] = 1;
                cout << "Success\n";
            }
            else
                cout << "Conflict with " << ans << endl;
        }
        else
        {
            if (!ada[ta])
            {
                cout << "Already off\n";
                continue;
            }
            int tmp = ta;
            vector<int> factors;
            for (int i = 0 ; primes[i] * primes[i] <= tmp ; i++) if (tmp % primes[i] == 0)
            {
                factors.push_back(primes[i]);
                while (tmp % primes[i] == 0)
                    tmp /= primes[i];
            }
            if (tmp >= 2) factors.push_back(tmp);
            for (auto it : factors) rep[it] = -1;
            ada[ta] = 0;
            cout << "Success\n";
        }
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
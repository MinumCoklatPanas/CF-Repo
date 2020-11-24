#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool isPrime[100010];
vector<ll> primes;

void prec()
{
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1] = 0;
    for (int i = 2 ; i <= 100000 ; i++) if (isPrime[i])
    {
        primes.push_back(i);
        for (int j = i + i ; j <= 100000 ; j += i)
            isPrime[j] = 0;
    }
}

void solve()
{
    ll x;
    cin >> x;
    ll tmp = x;
    vector< pair<ll,ll> > factors;
    for (int i = 0 ; primes[i] * primes[i] <= x ; i++) if (x % primes[i] == 0)
    {
        factors.push_back({primes[i], 0});
        while (x % primes[i] == 0)
        {
            factors.back().second++;
            x /= primes[i];
        }
    }
    if (x >= 2) factors.push_back({x, 1});
    if (factors.size() == 1)
    {
        cout << factors.back().second << endl;
        for (int i = 1 ; i <= factors.back().second ; i++)
            cout << factors.back().first << " ";
        cout << endl;
        return;
    }
    int mx = 0;
    int simpan = -1;
    for (auto it : factors) if (it.second > mx)
    {
        mx = it.second;
        simpan = it.first;
    }
    cout << mx << endl;
    for (int i = 1 ; i < mx ; i++)
    {
        cout << simpan << " ";
        tmp /= simpan;
    }
    cout << tmp << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    prec();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
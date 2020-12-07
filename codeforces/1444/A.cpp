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
#define int long long

bool isPrime[100010];
vector<int> primes;
vector<pair<int,int>> factors;

void rec(int ix,int tot,int &b,int &ans)
{
    // cout << ix << " " << tot << " " << factors[ix].first << " " << factors[ix].second << " " << b << endl;
    if (ix == factors.size())
    {
        if (tot % b != 0) ans = max(ans,tot);
        return;
    }
    if (tot % b == 0) return;
    // cout << "yo\n";
    int pengali = 1;
    for (int i = 0 ; i <= factors[ix].second ; i++)
    {
        rec(ix + 1,tot * pengali,b,ans);
        pengali *= factors[ix].first;
    }
    return;
}

void solve()
{
    ll a,b;
    cin >> a >> b;
    if (a % b != 0)
        cout << a << endl;
    else
    {
        factors.clear();
        map<int,int> mp;
        int rem = a / b;
        int simpan = b;
        for (int i = 0 ; primes[i] * primes[i] <= b ; i++) if (b % primes[i] == 0)
        {
            while (b % primes[i] == 0)
            {
                mp[primes[i]]++;
                b /= primes[i];
            }
        }
        if (b >= 2) mp[b]++;
        for (int i = 0 ; primes[i] * primes[i] <= rem && i < primes.size() ; i++) if (rem % primes[i] == 0)
        {
            while (rem % primes[i] == 0)
            {
                mp[primes[i]]++;
                rem /= primes[i];
            }
        }
        if (rem >= 2) mp[rem]++;
        for (auto it : mp)
        {
            // cout << it.first << " " << it.second << endl;
            factors.push_back(it);
        }
        // return;
        int ans = 0;
        rec(0,1,simpan,ans);
        cout << ans << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1] = 0;
    for (int i = 2 ; i <= 100000 ; i++) if (isPrime[i])
    {
        primes.push_back(i);
        for (int j = i + i ; j <= 100000 ; j += i)
            isPrime[j] = 0;
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
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

bool isPrime[10000010];
vector<int> primes;

void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    set<int> ada;
    int ans = 1;
    for (auto it : tab)
    {
        int rep = 1;
        for (int i = 0 ; primes[i] * primes[i] <= it ; i++) if (it % primes[i] == 0)
        {
            int cnt = 0;
            while (it % primes[i] == 0)
            {
                ++cnt;
                it /= primes[i];
            }
            if (cnt & 1) rep *= primes[i];
        }
        if (it >= 2) rep *= it;
        // cout << rep << endl;
        auto it2 = ada.find(rep);
        if (it2 != ada.end())
        {
            ada.clear();
            ada.insert(rep);
            ++ans;
        }
        else
            ada.insert(rep);
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1] = 0;
    for (int i = 1 ; i <= 10000000 ; i++) if (isPrime[i])
    {
        primes.push_back(i);
        for (int j = i + i ; j <= 10000000 ; j += i)
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
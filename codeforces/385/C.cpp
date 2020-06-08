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

int frek[10000010];
pair<int,int> query[50010];
int pref[10000010];
bool isPrime[10000010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1] = 0;
    vector<int> primes;
    for (int i = 2 ; i <= 10000000 ; i++) if (isPrime[i])
    {
        primes.push_back(i);
        for (int j = i + i ; j <= 10000000 ; j += i)
            isPrime[j] = 0;
    }
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        frek[ta]++;
    }
    int q;
    cin >> q;
    vector<int> compress;
    for (int i = 1 ; i <= q ; i++)
    {
        cin >> query[i].first >> query[i].second;
    }
    for (auto it : primes)
    {
        for (int j = it ; j <= 10000000 ; j += it)
            pref[it] += frek[j];
    }
    for (int i = 1 ; i <= 10000001 ; i++)
        pref[i] += pref[i - 1];
    for (int i = 1 ; i <= q ; i++)
    {
        int l = min(10000001,query[i].first);
        int r = min(10000001,query[i].second);
        int ans = pref[r] - pref[l - 1];
        cout << ans << endl;
    }
    return 0;
}

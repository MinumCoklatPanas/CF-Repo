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

int tab[50];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,t;
    cin >> n >> t;
    for (int i = 1 ; i <= n ; i++) cin >> tab[i];
    vector<int> kiri,kanan;
    int hehe = n / 2;
    for  (int i = 1 ; i <= hehe ; i++) kiri.push_back(tab[i]);
    for (int i = hehe + 1 ; i <= n ; i++) kanan.push_back(tab[i]);
    vector< int > ambilKiri,ambilKanan;
    for (int i = 0 ; i < (1 << (kiri.size())) ; i++)
    {
        int sum = 0;
        for (int j = 0 ; j < kiri.size() ; j++) if (i & (1 << j))
        {
            sum += kiri[j];
        }
        ambilKiri.push_back(sum);
    }
    for (int i = 0 ; i < (1 << (kanan.size())) ; i++)
    {
        int sum = 0;
        for (int j = 0 ; j < kanan.size() ; j++) if (i & (1 << j))
        {
            sum += kanan[j];
        }
        ambilKanan.push_back(sum);
    }
    sort(ambilKiri.begin(),ambilKiri.end());
    sort(ambilKanan.begin(), ambilKanan.end());
    int ans = 0;
    for (auto it : ambilKiri) if (it <= t)
    {
        int rem = t - it;
        int pos = upper_bound(ambilKanan.begin(),ambilKanan.end(),rem) - ambilKanan.begin() - 1;
        if (pos >= 0)
            ans = max(ans,it + ambilKanan[pos]);
    }
    // return 0;

    for (auto it : ambilKanan) if (it <= t)
    {
        int rem = t - it;
        int pos = upper_bound(ambilKiri.begin(),ambilKiri.end(),rem) - ambilKiri.begin() - 1;
        if (pos >= 0)
            ans = max(ans,it + ambilKiri[pos]);
    }
    cout << ans << endl;
    return 0;
}
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

void solve()
{
    int n;
    cin >> n;
    vector<int> ganjil,genap;
    for (int i = 0 ; i < n ; i++)
    {
        int ta;
        cin >> ta;
        if (ta & 1)
            ganjil.push_back(ta);
        else
            genap.push_back(ta);
    }
    int ans = ganjil.size() * genap.size();
    ans += (genap.size() * (genap.size() - 1)) / 2;
    for (int i = 0 ; i < ganjil.size() ; i++)
    {
        for (int j = i + 1 ; j < ganjil.size() ; j++)
        {
            ans += __gcd(ganjil[i],ganjil[j]) > 1;
        }
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
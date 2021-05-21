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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    map<int,int> frek;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        frek[ta] += 1;
    }
    for (auto &it : frek)
    {
        int ix = it.first + 1;
        int num = it.second / 2;
        if (num > 0)
            frek[ix] += num;
        it.second %= 2;
    }
    // for (auto it : frek)
    //     cout << it.first << " " << it.second << endl;
    int farthest = 0;
    int nyala = 0;
    for (auto it : frek) if (it.second)
    {
        farthest = it.first;
        nyala++;
    }
    int ans = farthest + 1 - nyala;
    cout << ans << endl;
    return 0;
}
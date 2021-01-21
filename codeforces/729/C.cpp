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

struct car
{
    int cost;
    int fuel;
};

car tab[200010];
int n,k,s,t;

bool ok(vector<int> &range,int mx,int need)
{
    need -= mx - range.back();
    for (int i = range.size() - 2 ; i >= 0 ; i--)
    {
        if (need <= 0) return 1;
        int ubah = min(range[i] * 2,mx);
        need -= ubah - range[i];
    }
    return (need <= 0);
}

int findMin(int k)
{
    int mn = INF;
    for (int i = 1 ; i <= n ; i++) if (tab[i].fuel >= k)
        mn = min(mn,tab[i].cost);
    return mn;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> s >> t;
    if (s > t)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1 ; i <= n ; i++)
        cin >> tab[i].cost >> tab[i].fuel;
    vector<int> pos(k);
    for (auto &it : pos) cin >> it;
    pos.push_back(0);
    pos.push_back(s);
    sort(pos.begin(),pos.end());
    vector<int> range;
    for (int i = 1 ; i < pos.size() ; i++)
    {
        // cout << pos[i] - pos[i - 1] << endl;
        range.push_back(pos[i] - pos[i - 1]);
    }
    sort(range.begin(),range.end());
    int maxFuel = 0;
    for (int i = 1 ; i <= n ; i++) maxFuel = max(maxFuel,tab[i].fuel);
    if (maxFuel < range.back())
    {
        cout << -1 << endl;
        return 0;
    }
    int l = range.back();
    int r = min(l * 2,maxFuel);
    // cout << l << " " << r << endl;
    // cout << ok(range,999999995,2 * s - t) << endl;
    // return 0;
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        if (ok(range,mid,2 * s - t))
            r = mid;
        else
            l = mid + 1;
    }
    if (ok(range,l,2 * s - t))
        cout << findMin(l) << endl;
    else
    if (ok(range,r,2 * s - t))
        cout << findMin(r) << endl;
    else
        cout << -1 << endl;
    return 0;
}
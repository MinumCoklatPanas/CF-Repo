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

int a[100010];
int b[100010];
int c[100010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,l,r;
    cin >> n >> l >> r;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    vector<pair<int,int>> tab;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> c[i];
        tab.push_back({c[i],i});
    }
    sort(tab.begin(),tab.end());
    int curMin = l - r;
    int curMax = r - l;
    for (int i = 0 ; i < n ; i++)
    {
        int rem = n - i;
        if (curMax - curMin + 1 < rem)
        {
            cout << -1 << endl;
            return 0;
        }
        int minNeeded = max(l,a[tab[i].second] + curMin);
        if (minNeeded > r)
        {
            cout << -1 << endl;
            return 0;
        }
        b[tab[i].second] = minNeeded;
        curMin = b[tab[i].second] - a[tab[i].second] + 1;
        // cout << i << " " << curMin << endl;
    }
    for (int i = 1 ; i <= n ; i++)
        cout << b[i] << " ";
    cout << endl;
    return 0;
}
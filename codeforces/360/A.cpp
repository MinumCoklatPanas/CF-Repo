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

struct query
{
    int tipe,l,r,d;
};


int mx[5010];
int diff[5010];
int ans[5010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<query> tab;
    for (int i = 1 ; i <= n ; i++) mx[i] = INF;
    for (int i = 1 ; i <= m ; i++)
    {
        int tipe;
        cin >> tipe;
        int l,r,d;
        cin >> l >> r >> d;
        if (tipe == 1)
            for (int j = l ; j <= r ; j++) diff[j] += d;
        else
        {
            for (int j = l ; j <= r ; j++)
                mx[j] = min(mx[j],d - diff[j]);
        }
        tab.push_back({tipe,l,r,d});
    }
    for (int i = 1 ; i <= n ; i++) ans[i] = mx[i];
    for (auto it : tab)
    {
        if (it.tipe == 1)
            for (int i = it.l ; i <= it.r ; i++) mx[i] += it.d;
        else
        {
            int tmp = -INF;
            for (int i = it.l ; i <= it.r ; i++) tmp = max(tmp,mx[i]);
            if (tmp != it.d)
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for (int i = 1 ; i <= n ; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
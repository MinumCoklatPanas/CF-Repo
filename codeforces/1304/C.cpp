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

int tab[110];
int l[110];
int r[110];
int n,m;

set< pair<int,int> > st;

bool can(int L,int R,int k)
{
    return (L <= k && k <= R);
}

void solve()
{
    cin >> n >> m;
    int curTime = 0;
    for (int i = 1 ; i <= n ; i++)
        cin >> tab[i] >> l[i] >> r[i];
    int mn = m;
    int mx = m;
    for (int i = 1 ; i <= n ; i++)
    {
        int diff = tab[i] - curTime;
        curTime = tab[i];
        int newMn = mn - diff;
        int newMx = mx + diff;
        if (newMn > r[i] || newMx < l[i])
        {
            cout << "NO\n";
            return;
        }
        mn = max(newMn,l[i]);
        mx = min(newMx,r[i]);
    }   
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        solve();
    }
    return 0;
}
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
    // cerr << n << " n\n";
    vector<int> tab(n);
    vector<int> mx = {0,0,0};
    vector<int> ada = {0,0,0};
    bool ada1 = 0;
    for (auto &it : tab)
    {
        cin >> it;
        mx[it % 3] = max(mx[it % 3],it);
        ada[it % 3] = 1;
        ada1 |= (it == 1);
    }
    int maxAll = max(mx[0],max(mx[1],mx[2]));
    int need3 = maxAll / 3;
    if (!ada[2] && !ada[1])
        cout << need3 << endl;
    else
    {
        // cerr << maxAll << " " << need3 << endl;
        if (maxAll == mx[0])
        {
            int secondMax = max(mx[1],mx[2]);
            int needLagi = secondMax / 3;
            if (needLagi != mx[0] / 3)
                cout << need3 + 1 << endl;
            else
                cout << need3 + 2 << endl;
        }
        else
        if (maxAll == mx[1])
        {
            int secondMax = max(mx[0],mx[2]);
            int needLagi = secondMax / 3;
            if ((needLagi != mx[1] / 3 && !ada1) || !ada[2])
                cout << need3 + 1 << endl;
            else
                cout << need3 + 2 << endl;
        }
        else
        {

            if (mx[1] == 0)
                cout << need3 + 1 << endl;
            else
                cout << need3 + 2 << endl;
        }
    }
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
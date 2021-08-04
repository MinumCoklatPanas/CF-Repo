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
#define MULTI_TC 0

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
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    sort(tab.begin(),tab.end());
    int sum = 0;
    vector<int> taken;
    for (int i = 0 ; i < n ; i++)
    {
        if (sum + tab[i] > 710) break;
        sum += tab[i];
        taken.push_back(tab[i]);
    }
    if (taken.size() == 0)
        cout << "0 0\n";
    else
    {
        sum = 0;
        int penalty = 0;
        for (int i = 0 ; i < taken.size() ; i++)
        {
            if (sum + taken[i] <= 350)
                sum += taken[i];
            else
            {
                sum += taken[i];
                penalty += sum - 350;
            }
        }
        cout << taken.size() << " " << penalty << endl;
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
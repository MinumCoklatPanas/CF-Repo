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

void solve()
{
    int n;
    cin >> n;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    const auto isHill = [&] (int ix) -> bool
    {
        if (ix == 0 || ix == n - 1) return 0;
        return (tab[ix] > tab[ix - 1] && tab[ix] > tab[ix + 1]);
    };

    const auto isValley = [&] (int ix) -> bool
    {
        if (ix == 0 || ix == n - 1) return 0;
        return (tab[ix] < tab[ix - 1] && tab[ix] < tab[ix + 1]);
    };

    int curSum = 0;
    for (int i = 0 ; i < n ; i++)
        curSum += (isHill(i) || isValley(i));
    
    int ans = curSum;
    for (int i = 1 ; i < n - 1 ; i++)
    {
        int simpan = tab[i];
        if (isHill(i))
        {
            bool statusKiri = isValley(i - 1);
            bool statusKanan = isValley(i + 1);

            tab[i] = tab[i - 1];
            bool newStatusKiri = isValley(i - 1) || isHill(i - 1);
            bool newStatusKanan = isValley(i + 1) || isHill(i + 1);

            int delta = (newStatusKiri + newStatusKanan) - (statusKiri + statusKanan) - 1;
            ans = min(ans,curSum + delta);

            tab[i] = tab[i + 1];
            newStatusKiri = isValley(i - 1) || isHill(i - 1);
            newStatusKanan = isValley(i + 1) || isHill(i + 1);

            delta = (newStatusKiri + newStatusKanan) - (statusKiri + statusKanan) - 1;
            ans = min(ans,curSum + delta);
            tab[i] = simpan;
        }
        else
        if (isValley(i))
        {
            bool statusKiri = isHill(i - 1);
            bool statusKanan = isHill(i + 1);

            tab[i] = tab[i - 1];
            bool newStatusKiri = isHill(i - 1) || isValley(i - 1);
            bool newStatusKanan = isHill(i + 1) || isValley(i + 1);
            // cout << statusKiri << " " << statusKanan << endl;

            int delta = (newStatusKiri + newStatusKanan) - (statusKiri + statusKanan) - 1;
            ans = min(ans,curSum + delta);

            tab[i] = tab[i + 1];
            newStatusKiri = isHill(i - 1) || isValley(i - 1);
            newStatusKanan = isHill(i + 1) || isValley(i + 1);

            delta = (newStatusKiri + newStatusKanan) - (statusKiri + statusKanan) - 1;
            ans = min(ans,curSum + delta);
            tab[i] = simpan;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
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
    vector<int> tab(7);
    for (auto &it : tab) cin >> it;
    int a = tab[0];
    int b = tab[1];
    for (int i = 2 ; i < 7 ; i++)
    {
        int c = tab[i];
        vector<int> hehe = {a,b,c};
        vector<int> huhu;
        for (int j = 1 ; j < 8 ; j++)
        {
            int sum = 0;
            for (int k = 0 ; k < 3 ; k++) if (j & (1 << k))
                sum += hehe[k];
            huhu.push_back(sum);
        }
        sort(huhu.begin(),huhu.end());
        // for (auto it : huhu)
        //     cerr << it << " ";
        // cerr << endl << endl;
        if (huhu == tab)
        {
            cout << a << " " << b << " " << c << endl;
            return;
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
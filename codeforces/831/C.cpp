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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    vector<int> pref(n);
    pref[0] = tab[0];
    for (int i = 1 ; i < n ; i++) pref[i] = pref[i - 1] + tab[i];
    vector<int> val(k);
    for (auto &it : val) cin >> it;
    sort(val.begin(),val.end());
    set<int> ans;
    for (int i = 0 ; i < n ; i++)
    {
        int x = val[0] - pref[i];
        multiset<int> ms;
        for (int j = 0 ; j < n ; j++) if (i != j)
        {
            ms.insert(pref[j]);
        }
        bool can = 1;
        for (int j = 1 ; j < k ; j++)
        {
            int cari = val[j] - x;
            auto it = ms.find(cari);
            if (it == ms.end()) 
            {
                can = 0;
                break;
            }
            ms.erase(it);
        }
        if (can) ans.insert(x);
    }
    cout << ans.size() << endl;
}
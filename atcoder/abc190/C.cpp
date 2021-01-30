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
    int n,m;
    cin >> n >> m;
    vector< pair<int,int> > cond(m);
    for (auto &it : cond) cin >> it.first >> it.second;
    int k;
    cin >> k;
    vector< pair<int,int> > tab(k);
    for (auto &it : tab) cin >> it.first >> it.second;
    int mx = 0;
    for (int i = 0 ; i < (1 << k) ; i++)
    {
        vector<int> frek(n + 5,0);
        for (int j = 0 ; j < k ; j++)
        {
            if (i & (1 << j))
                frek[tab[j].first]++;
            else
                frek[tab[j].second]++;
        }
        int cnt = 0;
        for (auto it : cond)
            cnt += (frek[it.first] > 0 && frek[it.second] > 0);
        mx = max(mx,cnt);
    }
    cout << mx << endl;
    return 0;
}
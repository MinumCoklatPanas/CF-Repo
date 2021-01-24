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
    vector<int> tab(n),depth(n,0);
    for (auto &it : tab) cin >> it;
    depth[0] = 0;
    depth[1] = 1;
    int curDepth = 1;
    for (int i = 2 ; i < n ; i++)
    {
        if (tab[i] < tab[i - 1])
        {
            if (depth[curDepth - 1])
                --depth[curDepth - 1],++depth[curDepth];
            else
            {
                ++curDepth;
                --depth[curDepth - 1];
                ++depth[curDepth];
            }
            // cout << tab[i] << " " << curDepth << " " << depth[curDepth - 1] << endl;
        }
        else
            ++depth[curDepth];
        // cout << tab[i] << " ";
        // cout << depth[0] << " " << depth[1] << " " << depth[2] << " " << depth[3] << endl;
        
    }
    cout << curDepth << endl;
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
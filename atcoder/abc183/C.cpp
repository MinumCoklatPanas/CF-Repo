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

int dist[10][10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> tab;
    for (int i = 2 ; i <= n ; i++) tab.push_back(i);
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= n ; j++)
            cin >> dist[i][j];
    int ans = 0;
    do {
        int ret = 0;
        for (int i = 0 ; i + 1 < n - 1 ; i++)
            ret += dist[tab[i]][tab[i + 1]];
        ret += dist[1][tab[0]];
        ret += dist[tab.back()][1];
        // cout << ret << endl;
        ans += (ret == k);
    } while (next_permutation(tab.begin(), tab.end()));
    cout << ans << endl;
    return 0;
}
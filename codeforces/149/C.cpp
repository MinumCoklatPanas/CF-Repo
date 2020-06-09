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

pair<int,int> tab[100010];
vector<int> ans[2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> tab[i].first;
        tab[i].second = i;
    }
    sort(tab + 1,tab + n + 1);
    reverse(tab + 1,tab + n + 1);
    for (int i = 1 ; i <= n ; i++)
    {
        ans[i % 2].push_back(tab[i].second);
    }
    cout << ans[0].size() << endl;
    for (auto it : ans[0])
        cout << it << " ";
    cout << endl;
    cout << ans[1].size() << endl;
    for (auto it : ans[1])
        cout << it << " ";
    cout << endl;
    return 0;
}
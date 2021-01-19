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

vector<int> median(vector<int> &tab)
{
    vector<int> res(tab.size());
    res[0] = tab[0];
    res[tab.size() - 1] = tab.back();
    for (int i = 1 ; i + 1 < res.size() ; i++)
    {
        vector<int> tmp;
        tmp.push_back(tab[i - 1]);
        tmp.push_back(tab[i]);
        tmp.push_back(tab[i + 1]);
        sort(tmp.begin(),tmp.end());
        res[i] = tmp[1];
    } 
    return res;
}

bool ok(vector<int> &tab)
{
    vector<int> firstChange = median(tab);
    vector<int> secondChange = median(firstChange);
    return (firstChange == secondChange);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> tab(n);
    vector<int> changed(n,0);
    for (auto &it : tab) cin >> it;
    vector<int> tmp = median(tab);
    for (int i = 0 ; i < n ; i++)
    {
        changed[i] = tmp[i] != tab[i];
    }
    vector< pair<int,int> > range;
    for (int i = 0 ; i < n ; i++) if (changed[i])
    {
        if (range.empty() || range.back().second + 1 != i)
            range.push_back({i,i});
        else
            range.back().second++;
    }
    vector<int> ans = tab;
    int mx = 0;
    for (auto it : range)
    {
        mx = max(mx,it.second - it.first + 1);
        int l = it.first;
        int r = it.second;
        while (l <= r)
        {
            ans[l] = ans[l - 1];
            ans[r] = ans[r + 1];
            ++l;
            --r;
        }
    }
    cout << (mx + 1) / 2 << endl;
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}
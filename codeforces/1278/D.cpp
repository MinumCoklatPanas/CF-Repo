#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
typedef tree<int, null_type, less<int>,
rb_tree_tag,tree_order_statistics_node_update>
ordered_set;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int par[500010];
int numset;

int finds(int x)
{
    return (par[x] == x ? x : par[x] = finds(par[x]));
}

bool joins(int x,int y)
{
    // cout << x << " " << y << endl;
    // return 1;
    int px = finds(x);
    int py = finds(y);
    if (px == py) return 0;
    par[px] = py;
    --numset;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    numset = n;
    vector< pair<int,int> > tab(n);
    for (int i = 0 ; i < n ; i++)
    {
        cin >> tab[i].first >> tab[i].second;
        par[i] = i;
    }
    sort(tab.begin(),tab.end());
    int l = tab[0].first;
    int r = tab[0].second;
    for (int i = 0 ; i < n ; i++)
    {
        if (tab[i].first > r)
        {
            cout << "NO\n";
            return 0;
        }
        r = max(r,tab[i].second);
    }
    set<pair<int,int>> st;
    for (int i = 0 ; i < n ; i++)
    {
        st.insert({tab[i].second,i});
        auto it = st.upper_bound({tab[i].first,-INF});
        while (it != st.end())
        {
            // if (i == 1)
            // {
            //     cout << "yo\n";
            //     cout << (*it).first << " " << (*it).second << endl;
            // }
            if ((*it).first >= tab[i].second)
            {
                // cout << i << endl;
                break;
            }
            if (!joins((*it).second,i))
            {
                cout << "NO\n";
                return 0;
            }
            ++it;
        }
    }
    if (numset != 1)
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}
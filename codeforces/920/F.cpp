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

ll bit[300010];
int factors[1000010];
int tab[300010];
int n,q;

void upd(int x,int val)
{
    for ( ; x <= n ; x += (x & -x))
        bit[x] += val;
}

int query(int x)
{
    ll ret = 0;
    for ( ; x ; x -= (x & -x))
        ret += bit[x];
    return ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1 ; i <= 1000000 ; i++)
    {
        for (int j = i ; j <= 1000000 ; j += i)
            factors[j]++;
    }
    cin >> n >> q;
    set< pair<int,int> > st;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        if (tab[i] > 2)
            st.insert({i,tab[i]});
        upd(i,tab[i]);
    }
    while (q--)
    {
        int ask,a,b;
        cin >> ask >> a >> b;
        if (ask == 2)
        {
            ll ans = query(b) - query(a - 1);
            cout << ans << endl;
        }
        else
        {
            int cur = a - 1;
            while (cur <= b)
            {
                auto nxt = st.upper_bound(make_pair(cur,INF));
                if (nxt == st.end()) break;
                auto tmp = *nxt;
                int ix = tmp.first;
                int val = tmp.second;
                // cout << ix << " " << val << endl;
                // return 0;
                if (ix > b) break;
                int delta = factors[val] - val;
                upd(ix,delta);
                tab[ix] = factors[val];
                st.erase(nxt);
                if (tab[ix] > 2)
                    st.insert({ix,tab[ix]});
                cur = ix;
            }
        }
        // for (int i = 1 ; i <= n ; i++)
        //     cout << tab[i] << " ";
        // cout << endl;
    }
    return 0;
}
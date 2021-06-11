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
#define MULTI_TC 0

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
    int n;
    cin >> n;
    vector< vector<int> > pos(n);
    vector<int> ans(n + 1);
    int mx = 0;

    const auto ask = [&](int x,int y) -> int
    {
        cout << "? " << x << " " << y << endl;
        int ret;
        cin >> ret;
        return ret;
    };

    set<int> st;
    set<int> nums;
    for (int i = 1 ; i <= n ; i++)
    {
        st.insert(i);
        nums.insert(i);
    }

    for (int i = 1 ; i < n ; i++)
    {
        auto tmp = st.begin();
        int a = *tmp;
        ++tmp;
        int b = *tmp;
        int ab = ask(a,b);
        int ba = ask(b,a);
        if (ab > ba)
        {
            ans[a] = ab;
            st.erase(a);
            nums.erase(ab);
        }
        else
        {
            ans[b] = ba;
            st.erase(b);
            nums.erase(ba);
        }
    }
    ans[*st.begin()] = *nums.begin();
    cout << "! ";
    for (int i = 1 ; i <= n ; i++)
    {
        cout << ans[i];
        if (i == n)
            cout << endl;
        else
            cout << " ";
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
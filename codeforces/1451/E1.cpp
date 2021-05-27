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

int askAnd(int x,int y)
{
    cout << "AND " << x << " " << y << endl;
    int ret;
    cin >> ret;
    return ret;
} 

int askOr(int x,int y)
{
    cout << "OR " << x << " " << y << endl;
    int ret;
    cin >> ret;
    return ret;
}

int askXor(int x,int y)
{
    cout << "XOR " << x << " " << y << endl;
    int ret;
    cin >> ret;
    return ret;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> ans(n + 1,0);
    int and12 = askAnd(1,2);
    int or12 = askOr(1,2);
    int xor12 = or12 - and12;

    int and23 = askAnd(2,3);
    int or23 = askOr(2,3);
    int xor23 = or23 - and23;

    int and13 = askAnd(1,3);
    int xor13 = xor12 ^ xor23;
    int or13 = xor13 + and13;
    for (int i = 0 ; i < 16 ; i++)
    {
        if ((1 << i) & and12)
        {
            ans[1] |= (1 << i);
            ans[2] |= (1 << i);
            if ((1 << i) & and23)
            {
                ans[3] |= (1 << i);
            }
        }
        else
        if ((1 << i) & and13)
        {
            ans[1] |= (1 << i);
            ans[3] |= (1 << i);
        }
        else
        if ((1 << i) & and23)
        {
            ans[2] |= (1 << i);
            ans[3] |= (1 << i);
        }
        else
        if ((1 << i) & or12)
        {
            if ((1 << i) & or23)
            {
                ans[2] |= (1 << i);
            }
            else
                ans[1] |= (1 << i);
        }
        else
        if ((1 << i) & or13)
        {
            ans[3] |= (1 << i);
        }
    }
    for (int i = 4 ; i <= n ; i++)
    {
        int tmp = askXor(i - 1,i);
        ans[i] = tmp ^ ans[i - 1];
    }
    cout << "! ";
    for (int i = 1 ; i <= n ; i++)
        cout << ans[i] << " ";
    cout << endl;
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